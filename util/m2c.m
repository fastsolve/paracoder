function m2c(varargin)
% Wrapper for converting MATLAB code into a C library using MATLAB Coder. 
%
% Usage:
%    m2c <options> matlabfunc <args>
%
%    The following options can be used:
%
% OPTIMIZATION
%     -O1
%           Enable optimization for MATLAB Coder and and pass the -O1 
%           compiler option to the C compiler to enable basis optimization.
%     -O
%     -O2
%           Enable optimization for MATLAB Coder and also pass the -O2
%           compiler option to the C compiler to enable nearly all supported
%           optimizations for C that do not involve a space-speed tradeoff. 
%     -O3
%           Enable optimization for MATLAB Coder and also pass the -O3
%           compiler option to the C compiler to enabe all supported 
%           optimizations for C, including loop unrolling and function inlining.
%     -noinf (Default)
%           Disable support of NonFinite (inf and nan. It produces faster codes).
%     -inf
%           Enable support of NonFinite (inf and nan. It produces slower codes).
%     -acc
%           Enable acceleration support using multicore (OpenMP) and/or GPUs (OpenACC).
%     -lapack
%           Enable LAPACKE and link with MATLAB's builtin LAPACK library.
%
% DEBUGGING
%     -g
%           Preserve MATLAB code info in C code and compile C functions 
%           in debug mode. It can be used in conjunction with -O, -O1, etc.
%     -exe
%           Build a standalone executable in addition to generating the C code.
%           Only Linux and Mac are supported.
%     -ddd
%           Generate script for running the standalone executable in ddd.
%     -valgrind
%           Generate script for running the standalone executable in valgrind.
%     -efence
%           Link the executable with electric-fence for debugging memory.
%           Only Linux and Mac are supported.
%     -v
%           Verbose mode.
%
% PROFILING AND INSTRUMENTATION
%     -time
%           Insert timing statements into C code.
%     -pg
%           Compile standalone code with profiling enabled (Mac or Linux).
% OUTPUT C/C++ CODE
%     -c++
%           Generates C++ code instead of C code.
%     -m
%           Map different MATLAB functions into separate C files.
%     -64
%           Map int32 to int64.
%
% MISCELLANEOUS
%     -mex
%           Run the mex command in addition to generating the C files.
%     -force
%           Force to rebuild the mex function,
%     -args {...}
%           Argument specification for function. If present, it must
%           appear right after the M file. If not present, it will be
%           extracted from the MA file.
%
%     Note: Any unrecognized option will be passed to codegen.
%
%     Example usage: 
%       To generate code without MATLAB function inlining and with 
%       default C compiler optimization:
%            m2c matlabfunc
%
%       To generate code with MATLAB function inlining and with 
%       default C compiler optimization of level 1, 2, or 3:
%            m2c -O1 matlabfunc
%            m2c -O matlabfunc
%            m2c -O3 matlabfunc
%
%       To generate code without MATLAB function inlining, without C 
%       compiler optimization, and with MATLAB code preserved in C code:
%            m2c -g matlabfunc
%
%       To generate code with MATLAB function inlining, with C compiler
%       optimization of level 1, 2 or 3, and with MATLAB code preserved in C code:
%            m2c -O1 -g matlabfunc
%            m2c -O -g matlabfunc
%            m2c -O3 -g matlabfunc
%
% See also compile, m2mex, codegen.

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

if nargin<1 || match_option( args, '-h')
    help m2c; %#ok<MCHLP>
    return;
end

if isempty(func);
    error('m2mex:NoFileName', 'No function name was specified.');
end

[skipdepck, args] = match_option( args, '-force');
[genmex, args] = match_option( args, '-mex');
[genexe, args] = match_option( args, '-exe');

if genexe && ~isunix()
    fprintf('Warning: Building executable is not supported on PCs\n');
    genexe = false;
end

% Split filename into the path and filename
[mpath, func, mfile] = get_path_of_mfile( func);
cpath = [mpath 'codegen/lib/' func '/'];

if ~skipdepck && exist([cpath  '/mex_' func '.m'], 'file') && ...
        ckdep([cpath  '/mex_' func '.m'], mfile)
    disp(['C code for ' func ' is up to date.']);
    if genmex; run_mexcommand(cpath, func); end
    if genexe; run_execommand(cpath, func); end
    return;
end

% Parse all options
[debuginfo, args] = match_option( args, '-g');
[enableopt, args] = match_option( args, '-O');
[enableopt1, args] = match_option( args, '-O1');
[enableopt2, args] = match_option( args, '-O2');
[enableopt3, args] = match_option( args, '-O3');
[uselapack, args] = match_option( args, '-lapack');
[~, args] = match_option( args, '-noinf'); 
[enable_inf, args] = match_option( args, '-inf'); noinf = ~enable_inf;
[usecpp, args] = match_option( args, '-c++');
[enableomp, args] = match_option( args, '-acc');
[match, args] = match_option( args, '-m'); genSingleFile = ~match;
[enable64, args] = match_option( args, '-64');
[verbose, args] = match_option( args, '-v');

[efence, args] = match_option( args, '-efence');
[valgrind, args] = match_option( args, '-valgrind');
[ddd, args] = match_option( args, '-ddd');
[timing, args] = match_option( args, '-time');
[profile, args] = match_option( args, '-pg');

debuginfo = debuginfo || efence || valgrind || ddd;
dbg_opts = struct('valgrind', valgrind, 'efence', efence, ...
    'ddd', ddd, 'profile', profile, 'timing', timing, 'verbose', verbose);

if enableopt; enableopt2=true; end
enableopt = enableopt1 || enableopt2 || enableopt2;

% Determine whether to include mpi.h
if ckuse( mfile, 'MMPI_require_header')
    mpi_header = '#include "mpi.h"';
else
    mpi_header = '';
end

% Determine whether to include omp.h
if ckuse( mfile, 'MACC_require_header')
    omp_header = '#include "omp.h"';
else
    omp_header = '';
end

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
basecommand = 'codegen -config co_cfg ';

co_cfg = coder.config('lib');

if enableopt
    try co_cfg.BuildConfiguration = 'Faster Runs';
    catch; end %#ok<CTCH>
end

co_cfg.SaturateOnIntegerOverflow = false;
co_cfg.EnableVariableSizing = true;
cfg.PassStructByReference = true;
co_cfg.EnableMemcpy = true;

co_cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
if genSingleFile
    co_cfg.FilePartitionMethod = 'SingleFile';
else
    co_cfg.FilePartitionMethod = 'MapMFileToCFile';
end
warning('off', 'CoderFoundation:builder:TMFIncompatibilityWarningMATLABCoder');

co_cfg.GenerateMakefile = false;
co_cfg.GenCodeOnly = true;
co_cfg.GenerateReport = true;
co_cfg.InitFltsAndDblsToZero = false;
co_cfg.SupportNonFinite = ~noinf;
if usecpp
    co_cfg.TargetLang = 'C++';
    suf = 'cpp';
else
    co_cfg.TargetLang = 'C';
    suf = 'c';
end

co_cfg.CustomSourceCode = sprintf('%s\n',...
    mpi_header, omp_header, '#include "m2c.h"');

try co_cfg.CustomSymbolStrTmpVar = '$M$N';
catch; end %#ok<CTCH>
try co_cfg.MultiInstanceCode = true;
catch; end %#ok<CTCH>
try co_cfg.GenerateComments = debuginfo;
catch; end %#ok<CTCH>
try co_cfg.MATLABFcnDesc = debuginfo;
catch; end %#ok<CTCH>
try co_cfg.MATLABSourceComments = debuginfo;
catch; end %#ok<CTCH>
try co_cfg.PassStructByReference = true;
catch; end %#ok<CTCH>

if enableopt
    opts = '-O enable:inline';
else
    opts = '';
end

if uselapack
    try co_cfg.CustomLAPACKCallback = 'useBuiltinLAPACK';
    catch; end %#ok<CTCH>
end

%% Specify compiler options
if debuginfo; dbflags = ' -g'; else dbflags = ''; end
if enableopt3
    COptimFlags = ['-O3 -DNDEBUG' dbflags];
elseif enableopt2
    COptimFlags = ['-O2 -DNDEBUG' dbflags];
elseif enableopt1
    COptimFlags = ['-O1 -DNDEBUG' dbflags];
else
    COptimFlags = dbflags;
end
if verbose
    basecommand = [basecommand ' -v'];
end

%% Run command
command = strtrim([basecommand ' ' dbflags ' ' opts ' ' func ' ' args]);

if verbose
    disp('Running codegen with options:');
    disp(co_cfg);
end
disp(command); 
if exist(cpath,'dir')
    rmdir(cpath,'s');
end

olddir = pwd;
if ~isempty(mpath); cd(mpath); end
p = path;

try
    if exist('./codegen', 'dir'); addpath ./codegen; end %#ok<*MCAP>
    eval(command);
    path(p); cd(olddir);  %#ok<*MCCD>
catch err
    path(p); cd(olddir);  %#ok<*MCCD>
    fprintf(2, '%s', err.message);
    fprintf(2, 'Skipping compilation for function %s\n', func);
    return;
end

post_codegen([cpath func '.' suf], 'm2c', enableopt);

fix_rtwtypes( [cpath 'rtwtypes.h']);
if exist([cpath 'examples'], 'dir'); rmdir([cpath 'examples'], 's'); end
if exist([cpath 'interface'], 'dir'); rmdir([cpath 'interface'], 's'); end
if exist([cpath 'buildInfo.mat'], 'file'); delete([cpath 'buildInfo.mat']); end
if exist([cpath 'codeInfo.mat'], 'file'); delete([cpath 'codeInfo.mat']); end

if enable64
    convert64(cpath);
end

%% Also generate a wrapper for building MEX
if enableomp; args = [args ' -acc']; end

lib2mex([mpath func], COptimFlags, args, dbg_opts);

if ~genmex && ~genexe
    fprintf('To build the MEX file, use command (without quotes): "run %s".\n', ...
        [cpath 'mex_' func '.m']);
    fprintf('To build the EXE file, use command (without quotes): "run %s".\n', ...
        [cpath 'ld_' func '.m']);
else
    if genmex; run_mexcommand(cpath, func); end
    if genexe; run_execommand(cpath, func); end
end

end

function run_mexcommand(cpath, func)
command = [cpath 'mex_' func '.m'];

if exist(command, 'file'); run(command); end
end

function run_execommand(cpath, func)
command = [cpath 'ld_' func '.m'];

if exist(command, 'file'); run(command); end
end