function m2mex(varargin)
% Wrapper function for compiling M-files into a MEX function.
% Usage:
%       m2mex [-c|-g|-O|-omp|-force] matlabfunc <args>
%    where <args> are sepcifications for codegen in the format of -args...
%
%    The options can be any of the following:
%     -c
%           Generate C/C++ code and perform post-processing, without
%           building the mex file.
%     -O
%           Enable optimization (including inlining) and disable
%           memory integrity checking.
%     -inline
%           Enable inlining
%     -no-inline
%           Disable inliniing
%     -g
%           Enable debugging.
%     -profile
%           Enable profiling of the mex function using MATLAB Profiler.
%     -v
%           Verbose mode.
%     -omp
%           Enable support for OpenMP. It requires MOMP.
%     -force
%           Force to rebuild the mex function.
%     -args {...}
%           Argument specification for function. If present, it must
%           appear right after the M file. If not present, it will be
%           extracted from the MA file.
%     -mat, -noinf, -no-inf
%           For compatibiity with m2c and will be ignored
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

if isempty(func)
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


if ~skipdepck && ~isempty(mexfile) && isnewer(mexfile, [cpre '.h'])
    disp([func '.' mexext ' is up to date.']);
    return;
end

if ~exist('codegen.p', 'file') && ~exist('emlmex.p', 'file')
    error('m2mex:MissingCoder', ...
        'Cannot compile the code, since you have neither codegen nor emlmex.');
end

[enableopt, args] = match_option(args, '-O');
[enableopt1, args] = match_option(args, '-O1');
[enableopt2, args] = match_option(args, '-O2');
[enableopt3, args] = match_option(args, '-O3');
enableopt = enableopt || enableopt1 || enableopt2 || enableopt3;

if enableopt
    opts_opt = '-O enable:inline';
else
    opts_opt = '-O disable:inline';
end
[enableopt, args] = match_option(args, '-inline');
if enableopt
    opts_opt = '-O enable:inline';
end
[disableopt, args] = match_option(args, '-no-inline');
if disableopt
    opts_opt = '-O disable:inline';
end

[debuginfo, args] = match_option(args, '-g');
if debuginfo
    mexopt = '-g';
else
    mexopt = '';
end
[enableprofile, args] = match_option(args, '-profile');
if enableprofile
    opts_opt = [opts_opt ' -profile'];
end

[verbose, args] = match_option(args, '-v');

% Options for compatability with m2c
[~, args] = match_option(args, '-mex');
[~, args] = match_option(args, '-noinf');
[~, args] = match_option(args, '-no-inf');

[useCpp, args] = match_option(args, '-c++');
[useCxx, args] = match_option(args, '-cxx');
[useLangCpp, args] = match_option(args, '-lang:c++');
useCpp = useCpp || useCxx || useLangCpp;

% Determine whether to enable OpenMP
[enableomp, args] = match_option(args, '-omp');
if enableomp
    if ~verLessThan('matlab', '8.0.0') && hascodegen
        opts_opt = [opts_opt ' -O enable:OpenMP'];
    end
elseif ~verLessThan('matlab', '8.0.0') && hascodegen
    opts_opt = [opts_opt ' -O disable:OpenMP'];
end

if length(func)>2 && func(end-1)=='.'
    func = func(1:end-2);
end

% Extract arguments from M-code.
if isempty(regexp(args,'(\s|^)-args(\s|$)','once'))
    args = [extract_codegen_args([mfile(1:end-1), 'm']) ' ' args];
    altapis = [func, strtrim(strrep(regexp(args, ...
        '(\w+)\s+-args', 'match'), ' -args', ''))];
    if length(altapis)>1 % strip-out alternative names
        args = regexprep(args, '\s+\w+(\s+-args\s*\{[^\}]*\})', '$1');
    end
end


%% Set compiler option
if hascodegen
    co_cfg = coder.config('mex');
    co_cfg.FilePartitionMethod = 'SingleFile';
    co_cfg.GenerateReport = debuginfo;
    basecommand = 'codegen -config co_cfg ';

    co_cfg.CustomSourceCode = sprintf('%s\n', ...
        '#define M2C_OFFSET_PTR(a,b)           ((a)+(b))', ...
        '#define M2C_GET_FIELD(s,field)        (s)->field', ...
        '#define M2C_SET_FIELD(s,field,val)    (s)->field=val', ...
        '#define M2C_INTDIV(a,b)               ((int)(a) / (int)(b))', ...
        '#define M2C_DEBUG  1');
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
try co_cfg.EnableDebugging = debuginfo;
catch; end %#ok<*CTCH>
try co_cfg.GenerateComments = debuginfo;
catch; end %#ok<*CTCH>
try co_cfg.MATLABFcnDesc = debuginfo;
catch; end
try co_cfg.MATLABSourceComments = debuginfo;
catch; end

if useCpp
    co_cfg.TargetLang = 'C++';
    if isprop(co_cfg, 'DynamicMemoryAllocationInterface')
        co_cfg.DynamicMemoryAllocationInterface = 'C';
    end
else
    co_cfg.TargetLang = 'C';
end

incpath = ' -I codegen';
if exist([fileparts(which(func)) '/include'], 'dir')
    incpath = [incpath ' -I include'];
end


%% Run command
command = strtrim([basecommand ' ' mexopt ' ' opts_opt ...
    incpath ' -o ' func ' ' func ' ' args]);
if verbose
    disp('Running codegen with options:');
    disp(co_cfg);
end
disp(command);
olddir = pwd;
if ~isempty(mpath); cd(mpath); end
try
    eval(command);
    cd(olddir);
catch err
    cd(olddir);
    error('%s', err.message);
end
end

function args = codegen2eml_args(args)
% Convert codegen arguments to eml arguments.
args = strrep(args, '-args ', '-eg ');
args = strrep(args, 'coder.typeof(', 'emlcoder.egs(');
end

function [matched, args] = match_option(args, opt)

opt = strrep(opt, '+', '\+');
matched = ~isempty(regexp(args, ['(\s|^)' opt '(\s|$)'], 'once'));

if matched
    args = regexprep(args, ['(\s|^)' opt '(\s|$)'], '$2');
end
end
