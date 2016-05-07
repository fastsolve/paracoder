function m2c(varargin)
% Wrapper for converting MATLAB code into a C library using MATLAB Coder and
%    for building the C code into a MEX file or a standalone executable.
%
% Usage:
%    m2c <options> matlabFunc [-args {...}]
%
%  matlabFunc can be the function name or file name of the top-level
%  function to be converted into C.
%
%  -args {...}
%      Specifies the data types of the MATLAB function using the same format
%      as codegen. If given, it must appear right after matlabFunc.
%      The -args argument and everything after it will be passed to codegen.
%      If not present, the argument specification will be extracted from
%      the MATLAB file from the first comment block started with %#codegen.
%
%  The options for m2c have several groups, defined as follows:
%
% CODE GENERATION
%     -api {...} [Not yet implemented]
%           List functions for generating API calls. The arguments is a cell
%           array of character strings. E.g., -api {'func1', 'func2'}. Each
%           string can be a MATLAB expression. An API function must not be
%           inlined, which can be ensured by adding coder.inline('never') 
%           in the M code. Note that the top-level function is automatically 
%           an API function and need not be listed. This argument can be
%           repeated, and then the functions will be concatenated.
%     -no-inf
%     -noinf
%           Disable support of NonFinite (inf and nan). It produces faster codes.
%           This is the default.
%     -inf
%           Enable support of NonFinite (inf and nan). It produces slower codes.
%
% OPTIMIZATION
%     -Og
%           Disable function inlining for MATLAB Coder and pass the -Og
%           compiler option to the C compiler to enable basic optimizations
%           that do not affect debugging. This is the default mode.
%     -O0
%           Disable function inlining for MATLAB Coder and pass the -O0
%           compiler option to the C compiler to disable all optimizations.
%     -O1
%           Enable function inlining for MATLAB Coder and pass the -O1
%           compiler option to the C compiler to enable basic optimization.
%     -O
%     -O2
%           Enable function inlining for MATLAB Coder and also pass the -O2
%           compiler option to the C compiler to enable nearly all supported
%           optimizations that do not involve a space-speed tradeoff.
%     -O3
%           Enable function inlining for MATLAB Coder and also pass the -O3
%           compiler option to the C compiler to enable all supported
%           optimizations, including loop unrolling and function inlining.
%     -inline
%           Enable function inlining in MATLAB Coder. This is the default with
%           -O1, -O2 and -O3, and it overwrites the value set by -O0 and -Og.
%     -no-inline
%           Disable function inlining in MATLAB Coder. This is the default with 
%           -O0 and -Og, and it overwrites the value set by -O1, -O2, and -O3.
%
%     Note: If multiple optimization flags are specified, the highest level wins.
%
% PROFILING AND INSTRUMENTATION
%     -time
%     -time {...} [Not yet implemented]
%           List of functions for timing. The argument list is a cell array
%           of character strings. E.g., -time {'func1', 'func2'}. Each string
%           can be a MATLAB expression. The function to be timed must not
%           be inlined functions. This can be ensured by adding
%           coder.inline('never') in the M code. If the list is not given
%           after -time, then only the top-level function will be timed.
%     -gprof
%     -gprof {...}
%           Compile standalone code with profiling support and generate
%           a script to process results from gprof (Linux only).
%           The gprof command can be specified in the arglist.
%     -gcov
%     -gcov {...}
%           Compile standalone code with profiling support and generate
%           a script to process results from gcov (Linux and Mac).
%           The gcov command can be specified in the arglist.
%
% DEBUGGING
%     -g
%           Preserve MATLAB code info in C code and also generate source-level
%           debug information when compiling C.
%     -exe
%           Generate a MATLAB script for running the exe file from within
%           MATLAB for debugging in place of the M-file (Linux and Mac).
%     -ddd
%     -ddd {...}
%           Generate a script for running the standalone executable in ddd.
%           The ddd command can be listed in the arglist.
%     -valgrind
%     -valgrind {...}
%           Generate a script for running the standalone executable in valgrind.
%           The valgrind command can be listed in the arglist.
%
% BUILD CUSTOMIZATION
%     -cc {...}
%           Specify the C compiler. It overwrites the default complier
%           choice for both the mex file and the standalone executable. The
%           argument list is a cell array of character strings. E.g.,
%           -cc {'/usr/bin/gcc', '-Wall'}. Each string can be a MATLAB.
%            expression. The compiler is also used as linker.
%     -cflags {...}
%           Specify additional flags for the C compiler for building the
%           mex file and the standalone executable. The argument list
%           is a cell array of character strings. E.g., 
%           -cflags {'-O3 -NDEBUG'}. Each string can be a MATLAB expression.
%           It overwrites the default compiler flags set by -O?, -g, -gprof,
%           -gcov and any supported external libraries.
%     -mexflags {...}
%           Specify flags for the mex command. It overwrites the flags 
%           assigned by -O?, -cc -cflags options. The argument 
%           list is a cell array of character strings. E.g., 
%           -mexflags {'COPTIMFLAGS=''-O3 -NDEBUG'''}. Each string can be
%           a MATLAB expression.
%     -libs {...}
%           Specify additional libraries for linker when building both
%           the mex file and the standalone executable. The argument list
%           is a cell array of character strings. E.g., 
%           -libs {'-L/opt/local/lib', '-llapack'}. Each string can be
%           a MATLAB expression. They will be listed before the libraries
%           required by the supported external libraries.
%
% SUPPORTED EXTERNAL LIBRARIES
%     -mpi
%     -mpi {...} [Not yet implemented]
%           Enable support for MPI. The argument list is a cell array of 
%           character strings to be passed to the C compiler and linker. 
%           Each string can be a MATLAB expression. It requires MMPI.
%     -omp
%     -omp {...} [Not yet implemented]
%           Enable support for OpenMP. The argument list is a cell array of 
%           character strings to be passed to the C compiler and linker. 
%           Each string can be a MATLAB expression. It requires MACC.
%     -acc
%     -acc {...} [Not yet implemented]
%           Enable support for OpenACC. The argument list is a cell array of
%           character strings to be passed to the C compiler and linker. 
%           Each string can be a MATLAB expression. It requires MACC.
%     -petsc
%     -petsc {...} [Not yet implemented]
%           Enable support for OpenACC. The argument list is a cell array of
%           character strings to be passed to the C compiler and linker. 
%           Each string can be a MATLAB expression. It requires MACC.
%     -lapack
%     -lapack {...}
%           Enable LAPACKE and link with the LAPACK library specified in 
%           the list. The argument list is a cell array of character strings 
%           to be passed to the C compiler and linker. Each string can be 
%           a MATLAB expression. If the cell array is empty, then the 
%           MATLAB built-in LAPACK library will be used.
%     -efence
%     -efence {...}
%           Link the standalone executable with electric-fence for
%           debugging memory errors. The argument list is a cell array of
%           character string to be passed to the linker, such as
%  	        -efence {'-L/opt/local/lib', '-lefence'}. Each string can be
%           a MATLAB expression. It is most useful in conjunction with 
%           a debugger, such as ddd, for debugging segmentation faults.
%
% MISCELLANEOUS
%     -mex
%           Build the mex command in addition to generating the C files.
%     -force
%           Force to regenerate the C code.
%     -v
%           Verbose mode.
%     -?
%     -h
%     -help
%           Print out help.
%
%     Note: Any unrecognized option will be passed to codegen.
%
%     Example usage:
%       To generate code without MATLAB function inlining and with
%       default C compiler optimization flag (-Og):
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
    args = strtrim(sprintf(' %s', varargin{1:end-1}));
end

% Split filename into the path and filename
[mpath, func, mfile] = get_path_of_mfile(func);
cpath = [mpath 'codegen/lib/' func '/'];

m2c_opts = struct('codegenArgs', '', ...
    'debugInfo', false, ...
    'enableInline', false, ...
    'optLevel', 'g', ...
    'enableInf', false, ...
    'api', [], ...
    'timing', [], ...
    'lapack', [], ...
    'cc', [], ...
    'libs', [], ...
    'cflags', [], ...
    'mexflags', [], ...
    'mpiLibs', [], ...
    'ompLibs', [], ...
    'accLibs', [], ...
    'petsc', [], ...
    'gprof', [], ...
    'gcov', [], ...
    'valgrind', [], ...
    'ddd', [], ...
    'efence', [], ...
    'genMex', false, ...
    'genExe', false, ...
    'verbose', false, ...
    'suf', 'c', ...
    'gen64', false);

[force, args] = proc_options(args, '-force');
[m2c_opts.genMex, args] = proc_options(args, '-mex');
[m2c_opts.genExe, args] = proc_options(args, '-exe');

% Parse all options
[m2c_opts.debugInfo, args] = proc_options(args, '-g');
[match, args] = proc_options(args, '-O0'); if match; m2c_opts.optLevel = '0'; end
[match, args] = proc_options(args, '-Og'); if match; m2c_opts.optLevel = 'g'; end
[match, args] = proc_options(args, '-O1'); if match; m2c_opts.optLevel = '1'; end
[match, args] = proc_options(args, '-O2'); if match; m2c_opts.optLevel = '2'; end
[match, args] = proc_options(args, '-O3'); if match; m2c_opts.optLevel = '3'; end

m2c_opts.enableInline = m2c_opts.optLevel ~= '0' && m2c_opts.optLevel ~= 'g';
[match, args] = proc_options(args, '-no-inline'); if match; m2c_opts.enableInline = false; end
[match, args] = proc_options(args, '-inline'); if match; m2c_opts.enableInline = true; end

[~, args] = proc_options(args, '-noinf'); % Omit. This is the default behavior
[~, args] = proc_options(args, '-no-inf'); % Omit. This is the default behavior
[m2c_opts.enableInf, args] = proc_options(args, '-inf');

[~, args, m2c_opts.cc] = proc_options(args, '-cc');
[~, args, m2c_opts.cflags] = proc_options(args, '-cflags');
[~, args, m2c_opts.mexflags] = proc_options(args, '-mexflags');
[~, args, m2c_opts.libs] = proc_options(args, '-libs');

[~, args, m2c_opts.lapackLibs] = proc_options(args, '-lapack');
[~, args, m2c_opts.efence] = proc_options(args, '-efence');

[~, args, m2c_opts.mpiLibs] = proc_options(args, '-mpi');
[~, args, m2c_opts.ompLibs] = proc_options(args, '-omp');
[~, args, m2c_opts.accLibs] = proc_options(args, '-acc');


[~, args, m2c_opts.api] = proc_options(args, '-api');
[~, args, m2c_opts.timing] = proc_options(args, '-time');
[~, args, m2c_opts.valgrind] = proc_options(args, '-valgrind');
[~, args, m2c_opts.ddd] = proc_options(args, '-ddd');
[~, args, m2c_opts.gprof] = proc_options(args, '-gprof');
[~, args, m2c_opts.gcov] = proc_options(args, '-gcov');

m2c_opts.genExe = m2c_opts.genExe || ...
    ~isempty(m2c_opts.valgrind) || ~isempty(m2c_opts.ddd) || ...
    ~isempty(m2c_opts.gprof) || ~isempty(m2c_opts.gcov);

[m2c_opts.verbose, args] = proc_options(args, '-v');

% Process suppressed options
[multiFile, args] = proc_options(args, '-m');
if multiFile; warning('Option -m is suppresed.'); end

[m2c_opts.gen64, args] = proc_options(args, '-64'); % Not supported
if m2c_opts.gen64; warning('Option -64 is suppresed and no longer supported.'); end

[m2c_opts.useCpp, args] = proc_options(args, '-c++');  % Not supported
if m2c_opts.useCpp; warning('Option -c++ is suppresed and no longer supported.'); end

if m2c_opts.genExe && ~isunix()
    fprintf('Warning: Building executable is not supported on Windows PCs\n');
    m2c_opts.genExe = false;
end

% Determine whether to include mpi.h
if ckuse(mfile, 'MMPI_require_header')
    mpi_header = '#include "mpi.h"';
    if ~isempty(m2c_opts.mpiLibs);
        disp('MPI is required. Enabled automatically.');
        [~,~,m2c_opts.mpiLibs] = proc_options('-mpi', '-mpi');
    end
else
    mpi_header = '';
    if ~isempty(m2c_opts.mpiLibs)
        disp('MPI is not required. Disabled.');
        m2c_opts.mpiLibs = {};
    end
end

% Determine whether to include omp.h
if ckuse(mfile, 'MACC_require_header')
    if isempty(m2c_opts.accLibs) && isempty(m2c_opts.ompLibs)
        disp('OpenMP or OpenACC is required. Enabling OpenMP.');
        [~,~,m2c_opts.ompLibs] = proc_options('-omp', '-omp');
    end
    
    if isempty(m2c_opts.ompLibs)
        acc_header = '#include "omp.h"';
    elseif isempty(m2c_opts.accLibs)
        acc_header = '#include "openacc.h"';
    else
        acc_header = '';
    end
else
    acc_header = '';
    if ~isempty(m2c_opts.ompLibs)
        disp('OpenMP are not required. Disabled.');
        m2c_opts.ompLibs = {};
    end
    if ~isempty(m2c_opts.accLibs)
        disp('OpenAcc is not required. Disabled.');
        m2c_opts.accLibs = {};
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

regen_c = force || ~ckCompOpt(m2c_opts, 'codegen', [cpath  func '_mex.c']) || ...
    ~ckdep([cpath  func '_mex.c'], mfile);

if ~regen_c
    disp(['C code for ' func ' is up to date.']);
else
    %% Specify codegen config options
    co_cfg = coder.config('lib');
    co_cfg.SaturateOnIntegerOverflow = false;
    co_cfg.EnableVariableSizing = true;
    cfg.PassStructByReference = true;
    co_cfg.EnableMemcpy = true;
    
    co_cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
    co_cfg.FilePartitionMethod = 'SingleFile';
    warning('off', 'CoderFoundation:builder:TMFIncompatibilityWarningMATLABCoder');
    
    co_cfg.GenerateMakefile = false;
    co_cfg.GenCodeOnly = true;
    co_cfg.GenerateReport = true;
    co_cfg.InitFltsAndDblsToZero = false;
    co_cfg.SupportNonFinite = m2c_opts.enableInf;
    
    if m2c_opts.useCpp
        co_cfg.TargetLang = 'C++';
        m2c_opts.suf = 'cpp';
        warning('C++ code generation is not supported. Use at your own risk.');
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
    
    if ~isempty(m2c_opts.lapackLibs)
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
end

%% Generate MATLAB scripts for mex
if regen_c || ~ckCompOpt(m2c_opts, 'mex', [cpath  'mex_' func '.m'])
    writeMexScript(func, cpath, m2c_opts);
    
    % Write README file
    writeREADME(func, cpath, m2c_opts.genExe);
end

if ~m2c_opts.genMex
    fprintf('To build the MEX file, use command (without quotes): "run %s".\n', ...
        [cpath 'mex_' func '.m']);
else
    run_mexcommand(cpath, func);
end

%% Generate MATLAB scripts for exe if genexe is true.
if m2c_opts.genExe
    if regen_c || ~ckCompOpt(m2c_opts, 'exe', [cpath  'build_' func '_exe.m'])
        writeExeScripts(func, cpath, m2c_opts);
    end
    
    build_exe(cpath, func);
    fprintf(['To run the EXE file in MATLAB, ', ...
        'replace calls to ' func ' by run_' func '_exe.\n']);
end
end

function run_mexcommand(cpath, func)
command = [cpath 'mex_' func '.m'];

clear(command);
if exist(command, 'file'); run(command); end
end

function build_exe(cpath, func)
command = [cpath 'build_' func '_exe.m'];

clear(command);
if exist(command, 'file'); run(command); end
end

function [matched, args, list] = proc_options(args, opt)

opt = strrep(opt, '+', '\+');
matched = ~isempty(regexp(args, ['(\s|^)' opt '(\s|$)'], 'once'));

switch opt
    case {'-time', '-api', '-mpi', '-omp', '-acc', '-gprof', '-gcov', ...
            '-ddd', '-valgrind', '-petsc', '-lapack', '-efence'}
        % Process the list of functions
        list = {};
        if matched
            % Find list of string
            pair = regexp(args, ['(\s|^)' opt '(\s*{[^}]*})(\s|$)'], 'match');
            args = regexprep(args, ['(\s|^)' opt '(\s*{[^}]*})?(\s|$)'], '$3');

            for i=1:length(pair)
                list = [list, eval(regexprep(pair{i}, ['(\s|^)' opt '(\s|$)'], '$2'))]; %#ok<AGROW>
            end
            
            if isempty(list)
                if isequal(opt, '-lapack')
                    % Use MATLAB's built-in LAPACK library
                    list = {'-lmwlapack', '-lmwblas'};
                elseif isequal(opt, '-efence')
                    % Use default efence configuration
                    list = {'-lefence'};
                else
                    list = {''};
                end
            end
        end
    case {'-cc', '-libs', '-mexflags', '-cflags'}
        % Process the list of functions
        list = {};
        if matched
            % Find list of string
            pair = regexp(args, ['(\s|^)' opt '(\s*{[^}]*})(\s|$)'], 'match');
            args = regexprep(args, ['(\s|^)' opt '(\s*{[^}]*})?(\s|$)'], '$3');

            if length(pair)<1
                warning('m2c:argument', ...
                    'Option %s requires a cell-array argument after it.', opt);
                matched = false;
            else
                for i=1:length(pair)
                    list = [list, eval(regexprep(pair{i}, ['(\s|^)' opt '(\s|$)'], '$2'))]; %#ok<AGROW>
                end
            end
        end
    otherwise
        if matched
            args = regexprep(args, ['(\s|^)' opt '(\s|$)'], '$2');
        end
end
end
