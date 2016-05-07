function m2c(varargin)
% Wrapper for converting MATLAB code into a C library using MATLAB Coder. 
%
% Usage:
%    m2c <options> MatlabFunc [-args {...}]
%
%  MatlabFunc can be the function name or file name of the top-level
%  function to be converted into C.
%
%  -args {...}
%      Specifies the argument data types in the same format as codegen.
%      If present, it must appear right after the MATLAB function or file
%      name. The -args argument and everything after it are passed to codegen.
%      If not present, the argument specification will be extracted from
%      the MATLAB file from the line start with %#codegen.
%
%  The options for m2c have several groups, as explained below:
%
% OPTIMIZATION
%     -Og   Disable function inlining for MATLAB Coder and and pass the -Og
%           compiler option oto the C compiler to enable basic optimization.
%           (This is the default mode.)
%     -O0   Disable function inlining for MATLAB Coder and and pass the -O0
%           compiler option oto the C compiler to disable optimization.
%     -O1
%           Enable function inlining for MATLAB Coder and pass the -O1 
%           compiler option to the C compiler to enable basis optimization.
%     -O
%     -O2
%           Enable function inlining for MATLAB Coder and also pass the -O2
%           compiler option to the C compiler to enable nearly all supported
%           optimizations for C that do not involve a space-speed tradeoff. 
%     -O3
%           Enable function inlining for MATLAB Coder and also pass the -O3
%           compiler option to the C compiler to enabe all supported 
%           optimizations for C, including loop unrolling and function inlining.
%     -inline 
%           Enable function inlinin in MATLAB Coder. This is the default 
%           with -O1, -O, -O2, or -O3.
%     -no-inline
%           Dissable function inlinin in MATLAB Coder. This is the default
%           with -O0 and -Og.
% PARALLELIZATION
%     -mpi
%           Enable acceleration support for MPI.
%     -omp
%           Enable acceleration support for OpenMP.
%     -acc
%           Enable acceleration support for OpenACC.
%     -lapack
%           Enable LAPACKE and link with MATLAB's builtin LAPACK library.
%
%     Note: If multiple -O options are specified, the highest-leve wins.
%
% PROFILING AND INSTRUMENTATION
%     -time
%     -time {...}
%           List of functions for timing. The list is a cell array of 
%           characters. E.g., -time {'func1', 'func2'}. The function being
%           timed must not be inlined. This can be ensured by adding 
%           coder.inline('never') in the M code. If the list is not given
%           after -time, then only the top-level function will be timed.
%     -gprof
%           Compile standalone code with profiling support and generate 
%           a script to process results from gprof (Linux only).
%     -gcov
%           Compile standalone code with profiling support and generate 
%           a script to process results from gcov (Linux and Mac).
% DEBUGGING
%     -g
%           Preserve MATLAB code info in C code and generate source-level debug
%           information when compiling C.
%     -v
%           Verbose mode.
%     -exe
%           Generate a MATLAB script for calling the exe file from within 
%           MATLAB  for debugging. Only Linux and Mac are supported.
%     -ddd
%           Generate a script for running the standalone executable in ddd.
%     -valgrind
%           Generate a script for running the standalone executable in valgrind.
%     -efence
%           Link the executable with electric-fence for debugging memory.
%           Only Linux and Mac are supported.
%
% CODE GENERATION
%     -api {...}
%           List functions for generating API calls. The arguments is a cell 
%           array of characters. E.g., -api {'func1', 'func2'}. An API function
%           must not be inlined. This can be ensured by adding coder.inline('never')
%           in the M code. Note that the top-level function is automatically
%           an API function and does not need to be listed.
%     -noinf
%     -no-inf (Default)
%           Disable support of NonFinite (inf and nan. It produces faster codes).
%     -inf
%           Enable support of NonFinite (inf and nan. It produces slower codes).
%     -c++
%           Generates C++ code instead of C code.
%     -m
%           Map different MATLAB functions into separate C files.
%     -64
%           Map int32 to int64.
%
% MISCELLANEOUS
%     -mex
%           Build the mex command in addition to generating the C files.
%     -force
%           Force to regenerate the C code.
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

if nargin==0 || nargin==1 && (isequal(varargin{1}, '-?') || ...
        isequal(varargin{1}, '-h') || isequal(varargin{1}, '-help'))
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
    if strcmp(varargin{i}, '-args')
        func = varargin{i-1};
        args = strtrim(sprintf(' %s', varargin{i:end}));
        args = [strtrim(sprintf(' %s', varargin{1:i-2})) ' ' args]; %#ok<AGROW>
        break;
    end
end

if isempty(func)
    func = varargin{end};
    args = strtrim(sprintf(' %s', varargin{i:end-1}));
end

m2c_opts = struct('debugInfo', 0, 'optLevel', 'g', 'enableInf', 0, ...
    'enableInline', 0, 'suf', '.c', 'gen64', 0, 'multiFile', false, ...
    'useLapack', 0, 'api', [], 'timing', [], 'enableMpi', 0, 'enableOmp', 0, 'enableAcc', 0, ...
    'genMex', false, 'genExe', false, 'gprof', 0, 'gcov', 0, ...
    'valgrind', 0, 'efence', 0, 'ddd', 0, 'verbose', false, 'codegenArgs', '');

[~, args, m2c_opts.api] = match_option(args, '-api');
[~, args, m2c_opts.timing] = match_option(args, '-time');

[force, args] = match_option(args, '-force');
[m2c_opts.genMex, args] = match_option(args, '-mex');
[m2c_opts.genExe, args] = match_option(args, '-exe');
[m2c_opts.efence, args] = match_option(args, '-efence');
[m2c_opts.valgrind, args] = match_option(args, '-valgrind');
[m2c_opts.ddd, args] = match_option(args, '-ddd');
[m2c_opts.gprof, args] = match_option(args, '-gprof');
[m2c_opts.gcov, args] = match_option(args, '-gcov');

m2c_opts.genExe = m2c_opts.genExe || m2c_opts.efence ||...
    m2c_opts.valgrind || m2c_opts.ddd || m2c_opts.gprof || m2c_opts.gcov;

% Split filename into the path and filename
[mpath, func, mfile] = get_path_of_mfile(func);
cpath = [mpath 'codegen/lib/' func '/'];

% Parse all options
[m2c_opts.debugInfo, args] = match_option(args, '-g');
[match, args] = match_option(args, '-O0'); if match; m2c_opts.optLevel = '0'; end
[match, args] = match_option(args, '-Og'); if match; m2c_opts.optLevel = 'g'; end
[match, args] = match_option(args, '-O1'); if match; m2c_opts.optLevel = '1'; end
[match, args] = match_option(args, '-O2'); if match; m2c_opts.optLevel = '2'; end
[match, args] = match_option(args, '-O3'); if match; m2c_opts.optLevel = '3'; end

m2c_opts.enableInline = m2c_opts.optLevel ~= '0' && m2c_opts.optLevel ~= 'g';
[match, args] = match_option(args, '-no-inline'); if match; m2c_opts.enableInline = false; end
[match, args] = match_option(args, '-inline'); if match; m2c_opts.enableInline = true; end

[m2c_opts.useLapack, args] = match_option(args, '-lapack');
[~, args] = match_option(args, '-noinf'); % Omit. This is the default behavior
[~, args] = match_option(args, '-no-inf'); % Omit. This is the default behavior
[m2c_opts.enableInf, args] = match_option(args, '-inf');
[useCpp, args] = match_option(args, '-c++');
[m2c_opts.enableMpi, args] = match_option(args, '-mpi');
[m2c_opts.enableOmp, args] = match_option(args, '-omp');
[m2c_opts.enableAcc, args] = match_option(args, '-acc');
[m2c_opts.multiFile, args] = match_option(args, '-m');
[m2c_opts.gen64, args] = match_option(args, '-64');
[m2c_opts.verbose, args] = match_option(args, '-v');

if m2c_opts.genExe && ~isunix()
    fprintf('Warning: Building executable is not supported on Windows PCs\n');
    m2c_opts.genExe = false;
end

% Determine whether to include mpi.h
if ckuse(mfile, 'MMPI_require_header')
    mpi_header = '#include "mpi.h"';
    if ~m2c_opts.enableMpi;
        disp('MPI is required. Enabled automatically.');
        m2c_opts.enableMpi = true;
    end        
else
    mpi_header = '';
    if m2c_opts.enableMpi
        disp('MPI is not required. Disabled.');
        m2c_opts.enableMpi = false;
    end        
end

% Determine whether to include omp.h
if ckuse(mfile, 'MACC_require_header')
    if ~m2c_opts.enableAcc && ~m2c_opts.enableOmp
        disp('OpenMP or OpenACC is required. Enabling OpenMP.');
        m2c_opts.enableOmp = true;
    end
    
    if m2c_opts.enableOmp
        acc_header = '#include "omp.h"';
    elseif m2c_opts.enableAcc;
        acc_header = '#include "openacc.h"';
    else
        acc_header = '';
    end
else
    acc_header = '';
    if m2c_opts.enableOmp
        disp('OpenMP are not required. Disabled.');
        m2c_opts.enableOmp = false;
    end        
    if m2c_opts.enableAcc
        disp('OpenAcc is not required. Disabled.');
        m2c_opts.enableAcc = false;
    end
end

if isempty(regexp(args,'(^|\s)-args(\s|$)', 'once'))
    % Extract arguments from source code.
    args = [extract_codegen_args(mfile) ' ' args];
end
m2c_opts.codegenArgs = args;

len = length(func);
if len>2 && strcmp(func(len - [1, 0]), '.m')
    func(len - [1, 0]) = [];
end
if strcmp(func(end-1:end), '.m'); func = func(1:end-2); end

if ~force && exist([cpath  func '.c'], 'file') && ...
        ckdep([cpath  func '.c'], mfile) && ...
        ckCompOpt('codegen', [cpath  func '.c'], m2c_opts)
    disp(['C code for ' func ' is up to date.']);
    regen_c = false;
else
    %% Specify codegen config options
    co_cfg = coder.config('lib');
    co_cfg.SaturateOnIntegerOverflow = false;
    co_cfg.EnableVariableSizing = true;
    cfg.PassStructByReference = true;
    co_cfg.EnableMemcpy = true;
    
    co_cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
    if ~m2c_opts.multiFile
        co_cfg.FilePartitionMethod = 'SingleFile';
    else
        co_cfg.FilePartitionMethod = 'MapMFileToCFile';
    end
    warning('off', 'CoderFoundation:builder:TMFIncompatibilityWarningMATLABCoder');
    
    co_cfg.GenerateMakefile = false;
    co_cfg.GenCodeOnly = true;
    co_cfg.GenerateReport = true;
    co_cfg.InitFltsAndDblsToZero = false;
    co_cfg.SupportNonFinite = m2c_opts.enableInf;
    
    if useCpp
        co_cfg.TargetLang = 'C++';
        m2c_opts.suf = 'cpp';
    else
        co_cfg.TargetLang = 'C';
        m2c_opts.suf = 'c';
    end
    
    co_cfg.CustomSourceCode = sprintf('%s\n',...
        mpi_header, acc_header, '#include "m2c.h"');
    
    try co_cfg.CustomSymbolStrTmpVar = '$M$N';
    catch; end
    try co_cfg.MultiInstanceCode = true;
    catch; end
    try co_cfg.GenerateComments = debugInfo;
    catch; end
    try co_cfg.MATLABFcnDesc = debugInfo;
    catch; end
    try co_cfg.MATLABSourceComments = debugInfo;
    catch; end
    try co_cfg.PassStructByReference = true;
    catch; end
    
    if m2c_opts.useLapack
        try co_cfg.CustomLAPACKCallback = 'useBuiltinLAPACK';
        catch; end %#ok<CTCH>
    end
    
    %% Run command
    if m2c_opts.verbose
        disp('Running codegen with options:');
        disp(co_cfg);
    end
    
    olddir = pwd;
    if ~isempty(mpath); cd(mpath); end
    p = path;
    
    basecommand = 'codegen -config co_cfg ';
    
    if m2c_opts.enableInline
        opts = '-O enable:inline';
    else
        opts = '';
    end
    
    if m2c_opts.verbose; basecommand = [basecommand ' -v']; end
    
    command = strtrim([basecommand ' ' opts ' ' func ' ' args]);
    
    try
        if exist('./codegen', 'dir'); addpath ./codegen; end
        disp(command)
        eval(command);
        path(p); cd(olddir);
    catch err
        path(p); cd(olddir);
        fprintf(2, '%s', err.message);
        fprintf(2, 'Skipping compilation for function %s\n', func);
        return;
    end
    
    % Modify C code generated by codegen
    post_codegen(func, cpath, m2c_opts);

    % Write Mex file to annotate the options used in codegen
    [alt_nlhs, alt_nrhs] = writeMexFile(func, mpath, cpath, m2c_opts);
    
    % Write Exe file
    writeExeFile(func, cpath, m2c_opts, alt_nlhs, alt_nrhs);
    
    if exist([cpath 'rtwtypes.h'], 'file'); delete([cpath 'rtwtypes.h']); end
    if exist([cpath 'examples'], 'dir'); rmdir([cpath 'examples'], 's'); end
    if exist([cpath 'interface'], 'dir'); rmdir([cpath 'interface'], 's'); end
    
    regen_c = true;
end

%% Generate MATLAB scripts for mex
if regen_c || ~exist([cpath  'mex_' func '.m'], 'file') || ...
        ckCompOpt('mex', [cpath  'mex_' func '.m'], m2c_opts)
    writeMexScript(func, cpath, m2c_opts);
    
    % Write README file
    writeREADME(cpath, func, m2c_opts.genExe);
end

if ~m2c_opts.genMex
    fprintf('To build the MEX file, use command (without quotes): "run %s".\n', ...
        [cpath 'mex_' func '.m']);
else
    run_mexcommand(cpath, func); 
end

%% Generate MATLAB scripts for exe
if m2c_opts.genExe
    if regen_c || ~exist([cpath  'build_' func '_exe.m'], 'file') || ...
            ckCompOpt('exe', [cpath  'build_' func '_exe.m'], m2c_opts)
        writeExeScripts(func, cpath, m2c_opts);
    end
    
    build_exe(cpath, func);
    fprintf(['To run the EXE file in MATLAB, ', ...
        'replace calls to ' func ' by run_' func '_exe.\n']);
end
end

function run_mexcommand(cpath, func)
command = [cpath 'mex_' func '.m'];

if exist(command, 'file'); run(command); end
end

function build_exe(cpath, func)
command = [cpath 'build_' func '_exe.m'];

if exist(command, 'file'); run(command); end
end