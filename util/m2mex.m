function m2mex(varargin)
% Wrapper function for compiling M-files into a MEX function.
% Usage:
%       m2mex [-c|-g|-O|-acc|-force] matlabfunc <args>
%    where <args> are sepcifications for codegen in the format of -args...
%
%    The options can be any of the following:
%     -c
%           Generate C/C++ code and perform post-processing, without
%           building the mex file.
%     -O
%           Enable optimization (including inlining) and disable
%           memory integrity checking.
%     -g
%           Preserve MATLAB code info in C code and compile MEX functions 
%           in debug mode.
%     -v
%           Verbose mode.
%     -acc
%           Enable MATLAB Coder's built-in support of OpenMP. This only 
%           enables converting parfor in MATLAB into OpenMP code in C. 
%           To use the full features of OpenMP, use m2c and MACC.
%     -force
%           Force to rebuild the mex function.
%     -args {...}
%           Argument specification for function. If present, it must
%           appear right after the M file. If not present, it will be
%           extracted from the MA file.
%
%     Note: Any unrecognized option will be passed to codegen.
%     
%     Example usage: 
%       To generate code with memory integrity checking, without MATLAB 
%       function inlining, and with default C compiler optimization:
%            m2mex matlabfunc
%
%       To generate code without memory integrity checking and with default 
%       C compiler optimization:
%            m2mex -O matlabfunc
%
%       To generate code with memory integrity checking, without C compiler
%       optimization, and with MATLAB code preserved in C code:
%            m2mex -g matlabfunc
%
%       To generate code without memory integrity checking, without C compiler
%       optimization, and with MATLAB code preserved in C code:
%            m2mex -O -g matlabfunc
%
% See also compile, m2c, codegen.

%% Process arguments
func = '';
args = '';
for i=length(varargin)-1:-1:2
    if strcmp(varargin{i}, '-args')
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
        elseif ~strncmp(strtrim(varargin{i}), '-', 1)
            func = varargin{i};
        elseif isempty(args)
            args = varargin{i};
        else
            args = sprintf('%s %s', args, varargin{i});
        end
    end
end

if nargin<1 || match_option(args, '-h')
    help m2mex; %#ok<MCHLP>
    return;
end

if isempty(func); 
    error('m2mex:NoFileName', 'No function name was specified.');
end

% Determine whether you have codegen.
hascodegen = exist('codegen.p', 'file');

% Split filename into the path and filename
[mpath, func, mfile] = get_path_of_mfile(func);
mexfile = [mfile(1:end-1) mexext];
cpre = [mpath 'codegen/mex/' func '/' func];

[skipdepck, args] = match_option(args, '-force');
[cgonly, args] = match_option(args, '-c');


if ~skipdepck && ~isempty(mexfile) && ckdep(mexfile, mfile) && ...
        isnewer(mexfile, [cpre '.h'])
    disp([func '.' mexext ' is up to date.']);
    return;
end

if ~exist('codegen.p', 'file') && ~exist('emlmex.p', 'file')
    error('m2mex:MissingCoder', ...
        'Cannot compile the code, since you have neither codegen nor emlmex.');
end

% Determine whether to include mpi.h
if ckuse(mfile, 'MMPI_require_header')
    error('m2mex:MPIUnsupported', 'MPI is not supported in the mex mode. Use m2c instead.');
end

[enableopt, args] = match_option(args, '-O');
if enableopt
    opts_opt = '-O enable:inline';
else
    opts_opt = '-O disable:inline';
end

[debuginfo, args] = match_option(args, '-g');
if debuginfo
    mexopt = '-g';
else
    mexopt = '';
end
[verbose, args] = match_option(args, '-v');

% Determine whether to enable OpenMP
[enableomp, args] = match_option(args, '-acc');
if enableomp
    if ~verLessThan('matlab', '8.0.0') && hascodegen
        opts_opt = [opts_opt ' -O enable:OpenMP'];
    end
elseif ~verLessThan('matlab', '8.0.0') && hascodegen
    opts_opt = [opts_opt ' -O disable:OpenMP'];
end

% Extract arguments from M-code.
if isempty(regexp(args,'(\s|^)-args(\s|$)','once'))
    args = [extract_codegen_args([mfile(1:end-1), 'm']) ' ' args];
end
if length(func)>2 && func(end-1)=='.'
    func = func(1:end-2);
end

%% Set compiler option
if hascodegen
    co_cfg = coder.config('mex');
    co_cfg.FilePartitionMethod = 'SingleFile';
    co_cfg.GenerateReport = true;
    basecommand = 'codegen -config co_cfg ';

    co_cfg.CustomSourceCode = sprintf('%s\n', ...
        '#define M2C_OFFSET_PTR(a,b)    ((char *)a)+(b)', ...
        '#define M2C_CHK_OPAQUE_PTR(ptr,parent,offset) \', ...
        'if ((parent) && (ptr) != ((char*)mxGetData(parent))+(offset)) \', ...
        'm2cErrMsgIdAndTxt("opaque_ptr:ParentObjectChanged", \', ...
        '"The parent mxArray has changed. Avoid changing a MATLAB variable when dereferenced by an opaque_ptr."');
elseif exist('emlmex.p', 'file') && ~cgonly
    args = codegen2eml_args(args);
    co_cfg = emlcoder.CompilerOptions;
    basecommand = 'emlmex -s co_cfg ';
    warning('off','Coder:common:EMLMEXDeprecation');
    warning('off','Coder:common:EMLMEXDeprecationFIACCEL');
else
    error('Could not compiel file %s', func);
end

if verbose
    basecommand = [basecommand ' -v'];
end

co_cfg.ExtrinsicCalls = true;
co_cfg.SaturateOnIntegerOverflow = false;
co_cfg.EnableVariableSizing = true;
co_cfg.EnableMemcpy = true;

co_cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';

co_cfg.IntegrityChecks = ~enableopt;
co_cfg.ResponsivenessChecks = ~enableopt;
try co_cfg.GenerateComments = debuginfo;
catch; end %#ok<*CTCH>
try co_cfg.MATLABFcnDesc = debuginfo;
catch; end
try co_cfg.MATLABSourceComments = debuginfo;
catch; end

%% Run command
command = strtrim([basecommand ' ' mexopt ' ' opts_opt ...
    ' -o ' func ' ' func ' ' args]);
if verbose
    disp('Running codegen with options:');
    disp(co_cfg);
end
disp(command);
olddir = pwd;
if ~isempty(mpath); cd(mpath); end
p = path;
try
    if exist('./codegen', 'dir'); addpath ./codegen; end %#ok<*MCAP>
    eval(command);
    % Recover path
    path(p); cd(olddir);  %#ok<*MCCD>
catch err
    path(p); cd(olddir);  %#ok<*MCCD>
    fprintf(2, '%s', err.message);
    fprintf(2, 'Skipping compilation for function %s\n', func);
    return;
end
end

function args = codegen2eml_args(args)
% Convert codegen arguments to eml arguments.
args = strrep(args, '-args ', '-eg ');
args = strrep(args, 'coder.typeof(', 'emlcoder.egs(');
end

function [matched, args] = match_option( args, opt)

opt = strrep( opt, '+', '\+');
matched = ~isempty( regexp( args, ['(\s|^)' opt '(\s|$)'], 'once'));

if matched;
    args = regexprep(args, ['(\s|^)' opt '(\s|$)'], '$2');
end
end
