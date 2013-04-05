function m2c(varargin)
% Wrapper function for converting Embedded MATLAB into a C library
%         that can be linked with other code.
% Usage:
%    m2c [-g|-O|-noinf|-mpi|-omp|-m|-64|-q] matlabfunc <args>
%
%    NOTE: This function requires MATLAB Coder.
%    The options can be any of the following:
%
%     -g 
%           Enable error checkings and debegging support.
%     -O
%           Enable optimization (including inlining).
%     -noinf
%           Disable support of NonFinite (inf and nan. It produces faster codes).
%     -mpi
%           Enable support of MPI (requires MMPI).
%     -omp
%           Enable full-featured support of OpenMP (requires MOMP).
%     -m 
%           Map MATLAB files to individual C files.
%      -q
%           Quite mode.
%     -64 
%           Map int32 to int64.
%
%     You can also use more than one option. E.g.,
%       m2c -g -O matlabfunc -args {code.typeof(0,[inf,1],[1,0])}
%
%     Note that if -args is present, it must follow matlabfunc.
%     Unrecognized options will be passed to codegen.
%
% See also compile, m2mex, codegen.

if nargin<1
    help m2c; %#ok<MCHLP>
    return;
end

% Determine whether you have codegen.
if ~exist('codegen.p', 'file')
    error('m2c:MissingCoder', 'MATLAB Coder is required for m2c.');
end

%% Process arguments
func = '';
args = '';
for i=length(varargin)-1:-1:2
    if strcmp( varargin{i}, '-args')
        func = varargin{i-1};
        args = strtrim(sprintf(' %s', varargin{i:end}));
        args = [strtrim(sprintf(' %s', varargin{1:i-2})) ' ' args]; %#ok<AGROW>
        break;
    end
end

if isempty(func)
    for i=1:length(varargin)
        if isempty(varargin{i})
            continue;
        elseif ~strncmp( strtrim(varargin{i}), '-', 1)
            func = varargin{i};
        elseif isempty(args)
            args = varargin{i};
        else
            args = sprintf('%s %s', args, varargin{i});
        end
    end
end
if isempty(func); 
    error('m2mex:NoFileName', 'No function name was specified.');
end

% Split filename into the path and filename
[mpath, func, mfile] = get_path_of_mfile( func);
cpath = [mpath 'codegen/lib/' func '/'];
[errchk, args] = match_option( args, '-g');
if errchk; dbopt = '-g'; else dbopt = ''; end

[enableopt, args] = match_option( args, '-O');

% Determine whether to include mpi.h
[enablempi, args] = match_option( args, '-mpi');
if enablempi
    if ~exist('MMPI_Init', 'file')
        error('-mpi requires MMPI.');
    end
    mpi_header = '#include "mpi.h"';
else
    mpi_header = '';
end

% Determine whether to include omp.h
[enableomp, args] = match_option( args, '-omp');
if enableomp; 
    if ~exist('MOMP_begin_parallel', 'file')
        error('-omp requires MOMP.');
    end
    omp_header = '#include "omp.h"'; 
else
    omp_header = '';
end

% Determine whether to support infinity
[noinf, args] = match_option( args, '-noinf');

% Determine quiet mode
[quiet, args] = match_option( args, '-q');

% Determine to generate single file or multiple files
[match, args] = match_option( args, '-m');
genSingleFile = ~match;

[enable64, args] = match_option( args, '-64');

if isempty( regexp(args,'(^|\s)-args(\s|$)', 'once'))
    % Extract arguments from source code.
    args = [extract_codegen_args( mfile) ' ' args];
end

len = length(func);
if len>2 && strcmp(func(len - [1, 0]), '.m')
    func(len - [1, 0]) = [];
end
if strcmp( func(end-1:end), '.m'); func = func(1:end-2); end

%% Set compiler option
basecommand = 'codegen -config co_cfg_lib ';

co_cfg_lib = coder.config('lib');

co_cfg_lib.SaturateOnIntegerOverflow = false;
co_cfg_lib.EnableVariableSizing = true;
co_cfg_lib.DynamicMemoryAllocation = 'AllVariableSizeArrays';
if genSingleFile
    co_cfg_lib.FilePartitionMethod = 'SingleFile';
else
    co_cfg_lib.FilePartitionMethod = 'MapMFileToCFile';
end
co_cfg_lib.GenerateMakefile = false;
co_cfg_lib.GenCodeOnly = true;
co_cfg_lib.GenerateReport = true;
co_cfg_lib.InitFltsAndDblsToZero = false;
co_cfg_lib.SupportNonFinite = ~noinf;

mex_header = sprintf('%s\n', ...
    '#include "stdio.h"', ...
    '#define M2C_ADD(a,b)    (a)+(b)', ...
    '#ifdef BUILD_MEX', ...
    '/* Define macros to support building function into MATLAB executable. */', ...
    '#include "mex.h"', ...
    '#define malloc  mxMalloc', ...
    '#define calloc  mxCalloc', ...
    '#define realloc mxRealloc', ...
    '#define free    mxFree', ...
    '#define emlrtIsMATLABThread(s)  1', ...
    '', ...
    '#define M2C_CHK_OPAQUE_PTR(ptr,parent,offset) \', ...
    '    if ((parent) && (ptr) != ((char*)mxGetData(parent))+(offset)) \', ...
    '        mexErrMsgIdAndTxt("opaque_ptr:ParentObjectChanged", \', ...
    '        "The parent mxArray has changed. Avoid changing a MATLAB variable when dereferenced by an opaque_ptr.");',...
    '#else', ...
    '#define emlrtIsMATLABThread(s)  0', ...
    '#define mexErrMsgIdAndTxt(a,b)   ', ...
    '#define M2C_CHK_OPAQUE_PTR(ptr,parent,offset) ', ...
    '#endif');
co_cfg_lib.CustomSourceCode = sprintf('%s\n',...
    mpi_header, omp_header, mex_header);

try co_cfg_lib.CustomSymbolStrTmpVar = '$M$N';
catch; end %#ok<CTCH>
try co_cfg_lib.MultiInstanceCode = true;
catch; end %#ok<CTCH>
try co_cfg_lib.GenerateComments = errchk;
catch; end %#ok<CTCH>
try co_cfg_lib.MATLABFcnDesc = errchk;
catch; end %#ok<CTCH>
try co_cfg_lib.MATLABSourceComments = errchk;
catch; end %#ok<CTCH>

if enableopt
    opts = '-O enable:inline';
else
    opts = '';
end

%% Run command
command = strtrim([basecommand ' ' dbopt ' ' opts ' ' func ' ' args]);
disp(command);
if exist(cpath,'dir')
    rmdir(cpath,'s');
end

try
    olddir = pwd;
    if ~isempty(mpath); cd(mpath); end
    if exist('./codegen', 'dir'); addpath ./codegen; end %#ok<*MCAP>
    eval(command);
    if exist('./codegen', 'dir'); rmpath ./codegen; end %#ok<*MCAP>
    cd(olddir);  %#ok<*MCCD>
catch err
    if exist('./codegen', 'dir'); rmpath ./codegen; end
    cd(olddir);
    fprintf(2, '%s', err.message);
    fprintf(2, 'Skipping compilation for function %s\n', func);
    return;
end

post_codegen([cpath func '.c'], 'm2c', enableopt);

fix_rtwtypes( [cpath 'rtwtypes.h']);

if enable64
    convert64(cpath);
end

%% Also generate a wrapper for building MEX
lib2mex([mpath func], dbopt, args);

if ~quiet
    fprintf('To build the MEX file, use command (without quotes): "run %scodegen/lib/%s/mex_%s.m".\n', ...
        mpath, func, func);
end

end
