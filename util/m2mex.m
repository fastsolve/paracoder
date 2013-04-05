function m2mex(varargin)
% Wrapper function for compiling M-files into a MEX function.
% Usage:
%       m2mex [-c|-g|-O|-mpi|-omp|-force] matlabfunc <args>
%    where <args> are sepcifications for codegen in the format of -args...
%
%    The options can be any of the following:
%     -c
%           Generate C/C++ code and perform post-processing, without
%           building the mex file.
%     -g
%           Compiles MEX functions in debug mode, with optimization turned off.
%     -O
%           Enable optimization (including inlining).
%     -mpi
%           Enable support of MPI (requires MATLAB Coder and MMPI.)
%     -omp
%           Enable support of OpenMP. This only enables converting
%           parfor in MATLAB into OpenMP code in C. To use the full
%           features of OpenMP, you need M2C and MOMP.
%     -force
%           Force to rebuild the mex function,
%
%     You can also use more than one option. For example,
%       m2mex -O -g matlabfunc -args {code.typeof(0,[inf,1],[1,0])}
%
%     Note that if -args is present, it must follow matlabfunc.
%     Unrecognized options will be passed to codegen.
%
% See also compile, m2c, codegen.

if nargin<1
    help m2mex; %#ok<MCHLP>
    return;
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

% Determine the file name.
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

% Determine whether you have codegen.
hascodegen = exist('codegen.p', 'file');

% Split filename into the path and filename
[mpath, func, mfile] = get_path_of_mfile( func);
mexfile = [mfile(1:end-1) mexext];
cpre = [mpath 'codegen/mex/' func '/' func];

[skipdepck, args] = match_option( args, '-force');
[cgonly, args] = match_option( args, '-c');


if ~skipdepck && ~isempty(mexfile) && ckdep( mexfile, mfile) && ...
        isnewer(mexfile, [cpre '.h'])
    disp([func '.' mexext ' is up to date.']);
    return;
end

if ~exist('codegen.p', 'file') && ~exist('emlmex.p', 'file')
    error( 'm2mex:MissingCoder', ...
        'Cannot compile the code, since you have neither codegen nor emlmex.');
end

[errchk, args] = match_option( args, '-g');
[enableopt, args] = match_option( args, '-O');

if enableopt
    opts_opt = '';  errchk=false;
    mexopt = ''; enableopt=true;
elseif errchk
    opts_opt = '-O disable:inline'; errchk=true;
    mexopt = '-g';  enableopt=false;
else
    opts_opt = '-O enable:inline';  errchk=false;
    mexopt = ''; enableopt=false;
end

% Determine whether to include mpi.h
[enablempi, args] = match_option( args, '-mpi');
if enablempi
    if ~hascodegen || ~exist('MMPI_Init', 'file')
        error('-mpi requires CodeGen and MMPI.');
    end
    mpi_header = '#include "mpi.h"';
else
    mpi_header = '';
end

% Determine whether to enable OpenMP
[enableomp, args] = match_option( args, '-omp');
if enableomp
    opts_opt = [opts_opt ' -O enable:OpenMP'];
    ompopt = '-lgomp';
else
    opts_opt = [opts_opt ' -O disable:OpenMP'];
    ompopt = '';
end

% Extract arguments from M-code.
if isempty(regexp(args,'(\s|^)-args(\s|$)','once'))
    args = [extract_codegen_args( [mfile(1:end-1), 'm']) ' ' args];
end
if length(func)>2 && func(end-1)=='.'
    func = func(1:end-2);
end

%% Set compiler option
if hascodegen
    co_cfg_mex = coder.config('mex');
    co_cfg_mex.FilePartitionMethod = 'SingleFile';
    co_cfg_mex.GenerateReport = true;
    basecommand = 'codegen -config co_cfg_mex -c ';
        
    co_cfg_mex.CustomSourceCode = sprintf('%s\n', ...
        '#define M2C_ADD(a,b)    (a)+(b)', ...
        '#define M2C_CHK_OPAQUE_PTR(ptr,parent,offset) \', ...
        '    if ((parent) && (ptr) != ((char*)mxGetData(parent))+(offset)) \', ...
        '        mexErrMsgIdAndTxt("opaque_ptr:ParentObjectChanged", \', ...
        '        "The parent mxArray has changed. Avoid changing a MATLAB variable when dereferenced by an opaque_ptr.");',...
        mpi_header);
elseif exist('emlmex.p', 'file') && ~cgonly
    args = codegen2eml_args( args);
    co_cfg_mex = emlcoder.CompilerOptions;
    basecommand = 'emlmex -s co_cfg_mex ';
    warning('off','Coder:common:EMLMEXDeprecation');
    warning('off','Coder:common:EMLMEXDeprecationFIACCEL');
else
    error('Could not compiel file %s', func);
end

co_cfg_mex.ExtrinsicCalls = true;
co_cfg_mex.SaturateOnIntegerOverflow = false;
co_cfg_mex.EnableVariableSizing = true;
co_cfg_mex.DynamicMemoryAllocation = 'AllVariableSizeArrays';

co_cfg_mex.IntegrityChecks = errchk;
co_cfg_mex.ResponsivenessChecks = errchk;
try co_cfg_mex.GenerateComments = errchk;
catch; end %#ok<CTCH>
try co_cfg_mex.MATLABFcnDesc = errchk;
catch; end %#ok<CTCH>
try co_cfg_mex.MATLABSourceComments = errchk;
catch; end %#ok<CTCH>

%% Run command
command = strtrim([basecommand ' ' mexopt ' ' opts_opt ' ' func ' ' args]);
disp(command);
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

% Perform post processing and compile
if strncmp( basecommand, 'codegen', 7) && exist([cpre '.h'], 'file')
    if exist([cpre '.c'], 'file')
        suffix = '.c';
    elseif exist([cpre '.cpp'], 'file')
        suffix = '.cpp';
    else
        error('m2mex:FileNotFound', ['Could not find file ' cpre  '.c or ' cpre  '.cpp.']);
    end
    
    post_codegen([cpre  suffix], 'm2mex', enableopt);
    if ~cgonly; cg2mex([mpath func], mexopt, ompopt); end
end
end

function args = codegen2eml_args( args)
% Convert codegen arguments to eml arguments.
args = strrep( args, '-args ', '-eg ');
args = strrep( args, 'coder.typeof(', 'emlcoder.egs(');
end
