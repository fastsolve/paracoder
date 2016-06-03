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
% COMPILATION WORKFLOW
%     -mex
%     -mex {'relative_path_to_m_file'}
%           By default, m2c only generates the C code. This options requests
%           m2c to build the mex function in addition to generating the C files.
%           By default, the mex file will be saved in the same directory
%           as the M file. If a parameter is given, it saves the mex file
%           to the specified directory, which should be a path relative to
%           the M file (such as 'mex').
%     -exe
%     -exe {'relative_path_to_m_file'}
%           Generate a MATLAB script for running the exe file from within
%           MATLAB for debugging in place of the M-file (for Linux and Mac).
%           By default, the exe file will be saved in the same directory
%           as the M file. If a parameter is given, it saves the exe file
%           to the specified directory, which should be a path relative to
%           the M file (such as 'exe').
%     -cktop
%           By default, m2c does not regenerated C code if it already exist.
%           Use this optoin to request m2c to check the dependecies of the
%           top-level M file and and regenerate C code. This is much faster,
%           than -ckdep, so it should be the default mode for most code development.
%     -ckdep
%           Use this optoin to request m2c to check the dependecies of the
%           M file and and regenerate C code if any dependence is newer.
%           This can be slow compared to -cktop, so it should be only if
%           you do not want to use -force.
%     -force
%           Force the regeneration of C code and recompilation.
%     -skipcg
%           Skip code generation and only perform recompilation, even if
%           -force, -ckdep, or -cktop is specified.
%
% CODE GENERATION OPTIONS
%     -no-inf
%     -noinf
%           Disable support of NonFinite (inf and nan). It produces faster codes.
%           This is the default.
%     -inf
%           Enable support of NonFinite (inf and nan). It produces slower codes.
%     -inline
%           Enable function inlining in MATLAB Coder. This is the default.
%           It can be overwritten by explicitly specifying -no-inline.
%     -no-inline
%           Disable function inlining in MATLAB Coder.
%     -typeRep
%           M2c uses the C built-in type names by default. This option requests
%           code generation to use the numeric types defined by Coder instead
%           of using the C built-in type names. This is the default if
%           write
%           is enabled for better portability.
%     -addpath {'dir1', 'dir2', ..., 'dirn'}
%           Add the directory to the beginning of the search path for M files
%           during code generation.
%     -api
%     -api {'expression1, 'expression2', ...}
%           Request m2c to generate API code to the list of functions and
%           include them in the header file. The argument list may be the
%           name of a single function or a cell array of MATLAB expressions
%           that evaluate to the names of the functions. An API function must
%           not be inlined, which can be ensured by adding coder.inline('never')
%           in the M code. Note that the top-level function is automatically
%           an API function and need not be listed. This argument can be
%           repeated, and then the functions will be concatenated.
%     -example
%           Generate example main file.
%     -config {'expression'}
%           Use the given coder.CodeConfig object for codegen. The argument
%           is a string contained a variable or function name that evaluates
%           to a coder.CodeConfig object in the MATLAB base workspace.
%           When this option is specified, code generation is forced.
%           If string is contained in a cell array, then the string can
%           be a MATLAB expression that evaluates to a character string.
%           This overwrites the default values used by m2c, except that the
%           headers for MPI, OpenMP etc. are appended to the given CustomSourceCode.
%
% COMPILER CUSTOMIZATION
%     -cc {'expression'}
%           Specify the C compiler. It overwrites the default complier
%           choice for both the mex file and the standalone executable.
%           The cc command can be specified after it as a character
%           string, or a MATLAB expression contained in a cell array.
%     -cflags {'flag1', 'flag2', ...}
%           Specify flags for the C compiler for building the mex file or
%           standalone executable. The argument list is a cell array of
%           character strings. E.g., -cflags {'-O3', '-DNDEBUG'}. Each
%           string can be a MATLAB expression. It overwrites the default
%           flags set by -O?, -g, -gprof, -gcov and any supported external
%           libraries.
%     -ldflags {'flag1', 'flag2', ...}
%           Specify flags for the linker when building the mex file or
%           standalone executable. It overwrites the default flags set by
%           any supported external libraries, so you must use with caution.
%     -mexflags {'flag1', 'flag2', ...}
%           Specify flags for the mex command. It overwrites the flags
%           assigned by -O?, -cc -cflags options. The argument list is a
%           cell array of character strings. Each string can be a MATLAB
%           expression. E.g., -mexflags {'COPTIMFLAGS=''-O3 -NDEBUG'''}.
%     -D'macro'
%           Add a definition of a macro for C preprocessor.
%     -I'dir'
%           Add search path for C header files.
%     -llib
%           Specify linking of a particular library.
%     -L'dir'
%     -L {'dir1', 'dir2', ..., 'dirn'}
%           Add search path for libraries for linking. In the second
%           format, -rpath will also be added automatically for linking
%           with shared libraries.
%
% OPTIMIZATION
%     -O0
%           Disable function inlining and variable reuse for MATLAB Coder,
%           and pass -O0 to the C compiler to disable all optimizations,
%           including all OpenMP pragma.
%     -O1
%           Enable function inlining for MATLAB Coder and pass the -O1
%           compiler option to the C compiler to enable basic optimization.
%     -O
%     -O2
%           Enable inlining for MATLAB Coder and pass -O2 to the C compiler
%           to enable nearly all supported optimizations that do not
%           involve a space-speed tradeoff.
%     -O3
%           Enable inlining for MATLAB Coder and pass -O3 to the C compiler
%           enable all supported optimizations, including loop unrolling
%           and function inlining.
%     -O4
%           Enable inlining and allow MATLAB Coder to reuse variable names
%           freely and set DynamicMemoryAllocation to Threshold. It also
%           passes -O3 to the C compiler. Ths generates unreadable C code,
%           so it should be used only for final "bindary" code distribution
%           for optimal performance.
% DEBUGGING
%     -g
%           Preserve MATLAB code info in C code and also generate 
%           source-level debug information when compiling C.
%     -chkmem
%           Generate code for runtime error checking of buffer overflow.
%           It also enables -g.
%     -ddd
%     -ddd {'expression'}
%           Generate a script for running the standalone executable in ddd.
%           The ddd command can be specified after it in a cell array.
%           It also activates -g and -chkmem.
%     -valgrind
%     -valgrind {'expression'}
%           Generate a script for running the standalone executable in valgrind.
%           The valgrind command can be specified after it as a character
%           string, or a MATLAB expression contained in a cell array. It
%           also activates -g and -chkmem.
%
% PROFILING AND INSTRUMENTATION
%     -time
%     -time {'expression1, 'expression2', ...} [Not yet implemented]
%           List of functions for timing. The argument list may be the name
%           of a single function or a cell array of expressions that
%           evaluate to the names of the functions to be timed. These
%           functions must not be inlined. This can be ensured by
%           adding coder.inline('never') in the M fiile. If no function is
%           given after -time, then the top-level function will be timed.
%           This argument can be repeated, and then the functions will
%           be concatenated.
%     -gprof
%     -gprof {'expression'}
%           Compile standalone code with profiling support and generate
%           a script to process results from gprof (Linux only).
%           The gprof command can be specified after it as a character
%           string, or a MATLAB expression contained in a cell array.
%     -gcov
%     -gcov {'expression'}
%           Compile standalone code with profiling support and generate
%           a script to process results from gcov (Linux and Mac).
%           The gcov command can be specified after it as a character
%           string, or a MATLAB expression contained in a cell array.
%
% SUPPORTED MATH LIBRARIES
%     -mkl (or -mkl-seq)
%     -mkl-iomp (or -mkl-omp}
%     -mkl {'expression'}
%           Enable Intel MKL and link with its BLAS and sparse BLAS libraries.
%           The root directory of MKL can be specified as an express
%           contained in a cell array, or be specified by the environment 
%           variables MKLROOT. By befault, -mkl specifies linking with 
%           the sequential version of MKL. Use -mkl-iomp to link with 
%           multithreaded MKL library with Intel OpenMP. Note that the
%           Intel OpenMP may conflict with GCC's OpenMP library, so it should
%           not be used with -omp when compiling with a non-Intel compiler.
%     -cuda
%     -cuda {'expression'}
%           Enable CUDA Toolkit and link with cuBLAS and cuSparse. The
%           root directory of CUDA can be specified by a MATLAB expression
%           contained in a cell array, or be specified by the environment
%           variables CUDA_PATH or by adding nvcc to your path. Note that
%           if CUDA is available within MATLAB (when MATLAB Parallel Toolbox
%           is installed), it will link with the CUDA libraries distributed
%           with MATLAB.
%     -petsc
%     -petsc {'expression'}
%           Enable support for PETSc. The root directory of PETSc can be
%           specified as a MATLAB expression contained in a cell array.
%           The default path can be extracted from the environment
%           variables PETSC_DIR and PETSC_ARCH.
%     -blas
%     -blas {'-Ldir1', '-llib1', '-llib2', ...}
%           Enable BLAS and link with the CBLAS library specified in
%           the list. The argument list is a cell array of character strings
%           to be passed to the C compiler and linker. Each string can be
%           a MATLAB expression. If the cell array is empty, then the
%           MATLAB built-in BLAS library will be used. This option is
%           omitted if -mkl is specified.
%     -lapack
%     -lapack {'-Ldir1', '-llib1', '-llib2', ...}
%           Enable LAPACKE and link with the LAPACK library specified in
%           the list. The argument list is a cell array of character strings
%           to be passed to the C compiler and linker. Each string can be
%           a MATLAB expression. If the cell array is empty, then the
%           MATLAB built-in LAPACK library will be used.
%
% PARALLEL PROGRAMMING
%     -omp
%     -omp {'-Ldir1', '-llib1', '-llib2', ...}
%           Enable support for OpenMP. The argument list is a cell array of
%           character strings to be passed to the C compiler and linker.
%           Each string can be a MATLAB expression. It requires MOMP and a
%           compiler that supports OpenMP.
%     -acc
%     -acc {'-Ldir1', '-llib1', '-llib2', ...}
%           Enable support for OpenACC. The argument list is a cell array of
%           character strings to be passed to the C compiler and linker.
%           Each string can be a MATLAB expression. It requires MOMP and a
%           compiler that supports OpenACC.
%     -mpi
%     -mpi {'-Ldir1', '-llib1', '-llib2', ...}
%           Enable support for MPI. The argument list is a cell array of
%           character strings to be passed to the C compiler and linker.
%           Each string can be a MATLAB expression. It requires MMPI.
%           This is not needed when -petsc is specified.
%
% MISCELLANEOUS
%     -v
%           Verbose mode.
%     -q
%           Quiet mode.
%     -?
%     -h
%     -help
%           Print out help.
%
% Example usage:
%       To generate code without MATLAB function inlining and with
%       default C compiler optimization flag (-O0):
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

[m2c_opts, matlabFunc] = proc_options(varargin{:});

if isempty(m2c_opts)
    help m2c; %#ok<MCHLP>
    return;
end

if isempty(matlabFunc)
    error('Missing function in the argument list.');
end

% Force code generation if config is specified
if ~isempty(m2c_opts.codegenConfig)
    m2c_opts.force = true;
end

m2c_opts.genExe = m2c_opts.genExe || ...
    ~isempty(m2c_opts.valgrind) || ~isempty(m2c_opts.ddd) || ...
    ~isempty(m2c_opts.gprof) || ~isempty(m2c_opts.gcov);

if m2c_opts.genExe && ~isunix()
    if ~m2c_opts.quiet
        fprintf('Warning: Building executable is not supported on Windows PCs\n');
    end
    m2c_opts.genExe = false;
end

%% Process arguments
% Split filename into the path and filename
[mpath, func, mfile] = get_path_of_mfile(matlabFunc);
cpath = [mpath 'codegen/lib/' func '/'];

if isempty(m2c_opts.codegenArgs) || ~isequal(m2c_opts.codegenArgs(1:5), -args)
    % Extract arguments from source code.
    m2c_opts.codegenArgs = [extract_codegen_args(mfile) ' ' m2c_opts.codegenArgs];
end

regen_c = ~m2c_opts.skipcg && (m2c_opts.force || ~exist([cpath  func '.c'], 'file') || ...
    ~exist([cpath  func '_mex.c'], 'file') || ...
    ~ckSignature(m2c_opts, 'codegen', [cpath  func '_mex.c']) || ...
    m2c_opts.cktop && ~isnewer([cpath  func '_mex.c'], mfile) || ...
    m2c_opts.ckdep && ~ckdep([cpath  func '.c'], mfile, true));

if regen_c
    % Determine whether you have codegen.
    if ~exist('codegen.p', 'file')
        error('m2c:MissingCoder', 'MATLAB Coder is required to generate C code.\n');
    end
    
    if ~isempty(m2c_opts.codegenConfig)
        co_cfg = evalin('base', sprintf('%s', m2c_opts.codegenConfig{1}));
        
        if isempty(co_cfg) || ~isa(co_cfg, 'coder.CodeConfig')
            error('m2c:WrongArgument', ['The argument after -config must evaluate to a coder.CodeConfig ' ...
                'object. Received %s Use command coder.config(''lib'') to create the object.\n'], ...
                m2c_opts.codegenConfig{1});
        end
    else
        %% Specify codegen config options
        co_cfg = coder.config('lib');
        co_cfg.EnableOpenMP = m2c_opts.withOMP && m2c_opts.optimLevel > 0;
        
        co_cfg.SaturateOnIntegerOverflow = false;
        co_cfg.EnableVariableSizing = true;
        cfg.PassStructByReference = true;
        co_cfg.EnableMemcpy = true;
        
        if ~isempty(m2c_opts.dynMem)
            co_cfg.DynamicMemoryAllocation = m2c_opts.dynMem;
        else
            co_cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
        end
        co_cfg.FilePartitionMethod = 'SingleFile';
        
        co_cfg.GenCodeOnly = true;
        co_cfg.GenerateReport = true;
        co_cfg.InitFltsAndDblsToZero = true;
        co_cfg.SupportNonFinite = m2c_opts.enableInf;
        
        if m2c_opts.useCpp
            co_cfg.TargetLang = 'C++';
            m2c_opts.suf = 'cpp';
        else
            co_cfg.TargetLang = 'C';
            m2c_opts.suf = 'c';
        end
        
        co_cfg.MultiInstanceCode = true;
        co_cfg.GenerateComments = m2c_opts.debugInfo;
        if ~isempty(m2c_opts.presVars)
            co_cfg.PreserveVariableNames = m2c_opts.presVars;
        else
            co_cfg.PreserveVariableNames = 'UserNames';
        end
        co_cfg.MATLABSourceComments = m2c_opts.debugInfo;
        co_cfg.RuntimeChecks = m2c_opts.chkMem || ~isempty(m2c_opts.ddd) || ~isempty(m2c_opts.valgrind);
        if ~m2c_opts.exampleMain
            co_cfg.GenerateExampleMain = 'DoNotGenerate';
        else
            co_cfg.GenerateExampleMain = 'GenerateCodeOnly';
        end
        co_cfg.GenerateMakefile = false;
        co_cfg.TargetLangStandard = 'C99 (ISO)'; % Set C99 standard
        if m2c_opts.typeRep || m2c_opts.withCuda
            % To support CUDA pointers, we need to use the bulit-in definition
            % of uint_64 for compatability with M.S. Windows, because MATLAB
            % Coder uses "unsigned long" for "uint64" in code generation.
            co_cfg.DataTypeReplacement = 'CoderTypeDefs';
        else
            co_cfg.DataTypeReplacement = 'CBuiltIn';
        end
        
        if m2c_opts.withLapack
            co_cfg.CustomLAPACKCallback = 'useBuiltinLAPACK';
        end
    end
    
    warning('off', 'CoderFoundation:builder:TMFIncompatibilityWarningMATLABCoder');
    if isequal(co_cfg.TargetLang, 'C++')
        warning('C++ code generation is not supported. Use at your own risk.');
    end
    
    co_cfg.CustomSourceCode = sprintf('%s\n', co_cfg.CustomSourceCode);
    
    %% Run command
    if m2c_opts.verbose
        disp('Running codegen with options:');
        disp(co_cfg);
    end
    
    basecommand = 'codegen -config co_cfg ';
    
    if m2c_opts.enableInline
        opts = '-O enable:inline';
    else
        opts = '-O disable:inline';
    end
    
    if m2c_opts.verbose; basecommand = [basecommand ' -v']; end
    basecommand = [basecommand sprintf(' %s ', '-I ./codegen', m2c_opts.addpath{:})];
    command = strtrim([basecommand ' ' opts ' ' func ' ' m2c_opts.codegenArgs]);
    
    try
        olddir = pwd;
        if ~isempty(mpath); cd(mpath); end
        if ~m2c_opts.quiet
            disp(command)
        end
        eval(command);
        cd(olddir);
    catch err
        cd(olddir);
        if ~m2c_opts.quiet
            fprintf(2, 'm2c: %s', err.message);
        end
        return;
    end
    
    % Modify C code generated by codegen
    post_codegen(func, cpath, m2c_opts);
    
    % Write Mex file to annotate the options used in codegen
    writeMexFile(func, mpath, cpath, m2c_opts);
    
    % Write README file
    writeREADME(func, cpath, m2c_opts.genExe);
    
    if exist([cpath 'rtwtypes.h'], 'file'); delete([cpath 'rtwtypes.h']); end
    if exist([cpath 'interface'], 'dir'); rmdir([cpath 'interface'], 's'); end
end

%% Generate MATLAB scripts for mex
if exist('octave_config_info', 'builtin')
    mexbuild = [cpath  'oct_' func '.m'];
else
    mexbuild = [cpath  'mex_' func '.m'];
end
if m2c_opts.genMex
    if regen_c || m2c_opts.force || ~ckSignature(m2c_opts, 'mex', mexbuild)
        writeMexScript(func, cpath, m2c_opts);
    end
    
    clear(mexbuild);
    if exist(mexbuild, 'file'); run(mexbuild); end
elseif m2c_opts.verbose
    fprintf('To build the MEX file, use command (without quotes): "run %s".\n', ...
        mexbuild);
end

%% Generate MATLAB scripts for exe if genexe is true.
if m2c_opts.genExe
    if regen_c || m2c_opts.force || ~exist([cpath  func '_exe.c'], 'file')
        % Write the main function for Exe
        writeExeFile(func, cpath, m2c_opts);
    end
    
    if regen_c || m2c_opts.force || ~ckSignature(m2c_opts, 'exe', [cpath  'build_' func '_exe.m'])
        % Write the build script for Exe
        writeExeScripts(func, cpath, m2c_opts);
    end
    
    if ~exist('octave_config_info', 'builtin')
        build_exe(cpath, func);
        if m2c_opts.verbose
            fprintf(['To run the EXE file in MATLAB, ', ...
                'replace calls to ' func ' by run_' func '_exe.\n']);
        end
    elseif ~m2c_opts.quiet
        fprintf('Skipping compilation of EXE file in Octave.\n');
        
    end
end
end

function [m2c_opts, func] = proc_options(varargin)
% Process input options from left to right.

func = '';

if nargin==0
    m2c_opts=[];
    return;
end

% If default value is {}, use [] in place of {} and re-assign default
% value to {} at the end.
m2c_opts = struct('codegenArgs', [], ...
    'codegenConfig', '', ...
    'debugInfo', false, ...
    'chkMem', false, ...
    'enableInline', true, ...
    'enableInf', false, ...
    'presVars', '', ...
    'dynMem', '', ...
    'optimLevel', 0, ...
    'typeRep', false, ...
    'addpath', '', ...
    'api', '', ...
    'timing', '', ...
    'cppflags', '', ...
    'libs', '', ...
    'cc', '', ...
    'cflags', '', ...
    'ldflags', '', ...
    'mexflags', '', ...
    'withMPI', false, ...
    'mpiCC', '', ...
    'mpiCXX', '', ...
    'mpiInc', '', ...
    'mpiLibs', '', ...
    'withOMP', false, ...
    'ompLibs', '', ...
    'withACC', false, ...
    'accLibs', '', ...
    'withBlas', false, ...
    'blasLibs', '', ...
    'withLapack', false, ...
    'lapackLibs', '', ...
    'withMKL', false, ...
    'mklDir', '', ...
    'mklInc', '', ...
    'mklLibs', '', ...
    'withCuda', false, ...
    'cudaDir', '', ...
    'cudaInc', '', ...
    'cudaLibs', '', ...
    'withPetsc', false, ...
    'petscDir', '', ...
    'petscCC', '', ...
    'petscCXX', '', ...
    'petscCFLAGS', '', ...
    'petscCXXFLAGS', '', ...
    'petscInc', '', ...
    'petscLibs', '', ...
    'gprof', '', ...
    'gcov', '', ...
    'valgrind', '', ...
    'ddd', '', ...
    'genMex', false, ...
    'mexDir', '', ...
    'genExe', false, ...
    'exeDir', '', ...
    'useCpp', false, ...
    'verbose', false, ...
    'quiet', false, ...
    'suf', 'c', ...
    'force', false, ...
    'ckdep', false, ...
    'cktop', false, ...
    'skipcg', false, ...
    'exampleMain', false);

names = fieldnames(m2c_opts);
for i=1:length(names)
    if ischar(m2c_opts.(names{i})) && isempty(m2c_opts.(names{i}))
        m2c_opts.(names{i}) = {m2c_opts.(names{i})};
    end
end

func_index = 0;
i = 1;
last_index = length(varargin);
while i<=last_index
    opt = varargin{i};
    switch opt
        case '-force'
            m2c_opts.force = true;
        case '-ckdep'
            m2c_opts.ckdep = true;
        case '-cktop'
            m2c_opts.cktop = true;
        case '-skipcg'
            m2c_opts.skipcg = true;
        case {'-addpath'}
            if i<last_index && varargin{i+1}(1) == '{'
                dirs = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index-1 && varargin{i+1}(1) ~= '-'
                dirs = varargin(i+1);
                i = i + 1;
            else
                error('m2c:wrong_argument', ...
                    'Argument %s requires a cell-array argument after it.\n', opt);
            end
            
            if ~isempty(dirs)
                m2c_opts.addpath = [m2c_opts.addpath  strtrim(sprintf('-I %s ', dirs{:}))];
            end
        case '-example'
            m2c_opts.exampleMain = true;
        case '-mex'
            m2c_opts.genMex = true;
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.mexDir = eval(varargin{i+1});
                i = i + 1;
            end
        case '-exe'
            m2c_opts.genExe = true;
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.exeDir = eval(varargin{i+1});
                i = i + 1;
            end
        case '-g'
            m2c_opts.debugInfo = true;
        case '-chkmem'
            m2c_opts.chkMem = true;
            m2c_opts.debugInfo = true;
        case '-O'
            m2c_opts.optimLevel = 2;
        case {'-O0'}
            m2c_opts.optimLevel = str2double(opt(3));
            m2c_opts.presVars = 'All';
        case {'-O1', '-O2', '-O3'}
            m2c_opts.optimLevel = str2double(opt(3));            
        case '-O4'
            m2c_opts.optimLevel = str2double(opt(3));
            m2c_opts.presVars = 'None';
            m2c_opts.dynMem = 'Threshold';
        case '-inline'
            m2c_opts.enableInline = true;
        case '-no-inline'
            m2c_opts.enableInline = false;
        case {'-noinf', '-no-inf'}
            m2c_opts.enableInf = false;
        case '-inf'
            m2c_opts.enableInf = true;
        case '-typeRep'
            m2c_opts.typeRep = true;
        case '-time'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.timing = eval(varargin{i+1});
                i = i + 1;
            else
                m2c_opts.timing = {''};
            end
        case '-api'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.api = eval(varargin{i+1});
                i = i + 1;
            else
                m2c_opts.api = {''};
            end
        case {'-valgrind', '-ddd', '-gprof', '-gcov'}
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.(opt(2:end)) = eval(varargin{i+1});
                i = i + 1;
            else
                m2c_opts.(opt(2:end)) = {''};
            end
        case {'-cc', '-mexflags', '-cflags', '-ldflags'}
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.(opt(2:end)) = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index-1 && varargin{i+1}(1) ~= '-'
                m2c_opts.(opt(2:end)) = varargin(i+1);
                i = i + 1;
            else
                error('m2c:wrong_argument', ...
                    'Argument %s requires a cell-array argument after it.\n', opt);
            end
        case '-L'
            if i<last_index && varargin{i+1}(1) == '{'
                dirs = eval(varargin{i+1});
                for k=1:length(dirs)
                    m2c_opts.libs = [m2c_opts.libs, dylibdir(dirs{k})];
                end
                i = i + 1;
            elseif i<last_index-1 && varargin{i+1}(1) ~= '-'
                m2c_opts.libs = [m2c_opts.libs, dylibdir(varargin{i+1})];
                i = i + 1;
            else
                error('m2c:wrong_argument', ...
                    'Argument -L requires a cell-array argument after it.\n');
            end
        case '-cuda'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.cudaDir = eval(varargin{i+1});
                i = i + 1;
            else
                if ~isempty(getenv('CUDA_PATH'))
                    m2c_opts.cudaDir = {getenv('CUDA_PATH')};
                elseif ismac && exist('/Developer/NVIDIA/CUDA-7.5', 'dir')
                    m2c_opts.cudaDir = {'/Developer/NVIDIA/CUDA-7.5'};
                else
                    error('m2c:cuda_dir', ...
                        ['Root directory of CUDA must be given after the ' ...
                        '-cuda flag or be specified by environment variable CUDA_PATH.\n']);
                end
            end
            m2c_opts.withCuda = true;
            m2c_opts.cudaInc = {['-I' m2c_opts.cudaDir{1} '/include']};
            m2c_opts.cudaLibs = {['-L' m2c_opts.cudaDir{1} '/lib'], '-lcublas', ...
                '-lcusparse', '-lcudart'}; % -lcusolver
        case {'-mkl', 'mkl-seq', '-mkl-iomp', '-mkl-omp'}
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.mklDir = eval(varargin{i+1});
                i = i + 1;
            else
                if ~isempty(getenv('MKLROOT'))
                    m2c_opts.mklDir = {getenv('MKLROOT')};
                elseif isunix && exist('/opt/intel/mkl', 'dir')
                    m2c_opts.mklDir = {'/opt/intel/mkl'};
                else
                    error('m2c:mkl_dir', ...
                        ['Root directory of MKL must be given after the ' ...
                        '-mkl flag or be specified by environment variable MKLROOT. \n' ...
                        'Intel MKL and TBB can be downloaded for free at ' ...
                        'https://software.intel.com/en-us/articles/free_mkl\n']);
                end
            end
            
            if m2c_opts.mklDir{1}(end)=='/' || m2c_opts.mklDir{1}(end)=='\'
                m2c_opts.mklDir{1}(end) = [];
            end
            m2c_opts.withMKL = true + ~isempty(strfind(opt, 'omp'));
            m2c_opts.mklInc = {['-I' m2c_opts.mklDir{1} '/include']};
            m2c_opts.mklLibs = {dylibdir([m2c_opts.mklDir{1} '/lib']), ...
                '-lmkl_intel_lp64', '-lmkl_core'};
            if isequal(opt, '-mkl-iomp')
                m2c_opts.mklLibs = [m2c_opts.mklLibs, ...
                    dylibdir([fileparts(m2c_opts.mklDir{1}) '/lib']), ...
                    '-lmkl_intel_thread', '-liomp5'];
            else
                m2c_opts.mklLibs = [m2c_opts.mklLibs, '-lmkl_sequential'];
            end
        case '-petsc'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.petscDir = eval(varargin{i+1});
                i = i + 1;
            else
                if ~isempty(getenv('PETSC_DIR')) && ~isempty(getenv('PETSC_ARCH'))
                    m2c_opts.petscDir = {[getenv('PETSC_DIR') '/' getenv('PETSC_ARCH')]};
                elseif ~isempty(getenv('PETSC_DIR'))
                    m2c_opts.petscDir = {getenv('PETSC_DIR')};
                else
                    error('m2c:petsc_dir', ...
                        ['Root directory of PETSc must be given after the ' ...
                        '-petsc flag or be specified by environment variable PETSC_DIR.\n']);
                end
            end
            
            petscvariables = [m2c_opts.petscDir{1} '/lib/petsc/conf/petscvariables'];
            if ~exist(petscvariables, 'file')
                error('m2c:petsc_dir', ...
                    ['Could not locate file lib/petsc/conf/petscvariables ' ...
                    'under the given petsc directory %s.\n'], m2c_opts.petscDir{1});
            end
            
            if ~exist([m2c_opts.petscDir{1} '/lib/libpetsc.so'], 'file') && ...
                    ~exist([m2c_opts.petscDir{1} '/lib/libpetsc.dylib'], 'file')
                error('m2c:petsc', ...
                    'PETSc must be built as a shared library in order to be used in MATLAB.\n');
            end
            
            [PCC, CXX, INC, CFLAGS, CXXFLAGS] = obtain_petscCC(petscvariables);
            if isempty(PCC)
                error('m2c:petsc_dir', ...
                    ['Could find the definition of PCC in lib/petsc/conf/petscvariables ' ...
                    'under the given petsc directory %s.\n'], m2c_opts.petscDir{1});
            end
            
            m2c_opts.petscCC = {PCC};
            m2c_opts.petscCXX = {CXX};
            m2c_opts.petscCFLAGS = {CFLAGS};
            m2c_opts.petscCXXFLAGS = {CXXFLAGS};
            
            mpetscInc = [fileparts(which('startup_mpetsc.m')), '/include'];
            m2c_opts.petscInc = {[INC ' -I' mpetscInc]};
            m2c_opts.petscLibs = {dylibdir([m2c_opts.petscDir{1}  '/lib']), ...
                '-lpetsc'};
            m2c_opts.withPetsc = true;
        case '-blas'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.blaskLibs = eval(varargin{i+1});
                i = i + 1;
            elseif ismac
                m2c_opts.blasLibs = {'-lblas'};
            else
                m2c_opts.blasLibs = {'-lmwblas'};
            end
            m2c_opts.withBlas = true;
        case '-lapack'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.lapackLibs = eval(varargin{i+1});
                i = i + 1;
            elseif ismac
                m2c_opts.lapackLibs = {'-llapack', '-lblas'};
            else
                m2c_opts.lapackLibs = {'-lmwlapack', '-lmwblas'};
            end
            m2c_opts.withLapack = true;
        case {'-omp', '-acc'}
            m2c_opts.(['with' upper(opt(2:end))])= true;
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.([opt(2:end) 'Libs']) = eval(varargin{i+1});
                i = i + 1;
            else
                m2c_opts.([opt(2:end) 'Libs']) = {''};
            end
        case {'-mpi'}
            m2c_opts.withMPI= true;
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.mpiLibs = eval(varargin{i+1});
                i = i + 1;
            else
                m2c_opts.mpiLibs = {''};
            end
            
            if ~isequal(m2c_opts.petscCC, {''})
                petsc_opts = m2c_opts;
            else
                petsc_opts = proc_options('-petsc');
            end
            if ~isempty(petsc_opts.petscCC)
                m2c_opts.mpiCC = petsc_opts.petscCC;
                m2c_opts.mpiCXX = petsc_opts.petscCXX;
            else
                m2c_opts.mpiCC = {'mpicc'};
                m2c_opts.mpiCXX = {'mpicc'};
            end
            
            mpiInc = [fileparts(which('startup_mmpi.m')), '/include'];
            m2c_opts.mpiInc = {['-I' mpiInc]};
        case '-config'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.codegenConfig = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index-1 && varargin{i+1}(1) ~= '-'
                m2c_opts.codegenConfig = varargin(i+1);
                i = i + 1;
            else
                error('m2c:wrong_argument', ...
                    'Argument %s requires a cell-array argument after it.\n', opt);
            end
        case '-v'
            m2c_opts.verbose = true;
        case '-q'
            m2c_opts.quiet = true;
        case '-m'
            warning('Option -m is suppresed.');
        case '-c++'
            m2c_opts.useCpp = true;
            warning('Option -c++ is suppresed and no longer supported.');
        case {'-h', '-?', '--help'}
            m2c_opts = [];
            return;
        otherwise
            if isequal(opt, '-args')
                if func_index==0 || func_index~=i-1
                    error('m2c:InvalidArgument', '-args must follow a function name.\n');
                elseif i==last_index || varargin{i+1}(1)~='{'
                    error('m2c:InvalidArgument', '-args must be followed by a cell array.\n');
                else
                    if isempty(m2c_opts.codegenArgs)
                        m2c_opts.codegenArgs = [opt ' ' varargin{i+1}];
                    else
                        m2c_opts.codegenArgs = sprintf('%s ', ...
                            m2c_opts.codegenArgs, opt, varargin{i+1});
                    end
                    i = i + 1;
                end
            elseif ~isempty(opt) && opt(1)~='-'
                if func_index==0
                    func_index = i;
                    if exist(opt, 'file') || exist([opt '.m'], 'file')
                        func = opt;
                    else
                        error('m2c:InvalidFileName', 'Function %s could not be found.\n', opt);
                    end
                elseif ~isempty(m2c_opts.codegenArgs) || func_index==i-3 && ...
                        i<last_index-2 && isequal(varargin{i+1}, '-args')
                    func_index = i;
                    m2c_opts.codegenArgs = sprintf('%s ', m2c_opts.codegenArgs, opt);
                else
                    error('m2c:wrong_argument', 'Unexpected string %s.\n', opt);
                end
            elseif length(opt)>=2 && (isequal(opt(1:2), '-D') || isequal(opt(1:2), '-I'))
                m2c_opts.cppflags = [m2c_opts.cppflags, opt];
            elseif length(opt)>=2 && (isequal(opt(1:2), '-L') || isequal(opt(1:2), '-l'))
                m2c_opts.libs = [m2c_opts.libs, opt];
            else
                error('m2c:wrong_argument', 'Unrecognized argument %s.\n', opt);
            end
    end
    i = i +1;
end

for i=1:length(names)
    if iscell(m2c_opts.(names{i})) && isequal(m2c_opts.(names{i}){1}, '')
        m2c_opts.(names{i})(1) = [];
    end
end

if exist('octave_config_info', 'builtin')
    % When running in octave, always skip codegen
    m2c_opts.skipcg = true;
end

if m2c_opts.withOMP && m2c_opts.withMKL>1 && isempty(m2c_opts.cc)
    fprintf(1, ['You are using OpenMP together with Intel OpenMP in MKL.\n', ...
        'This may cause conflicts! See https://software.intel.com/en-us/articles/recommended-settings', ...
        '-for-calling-intelr-mkl-routines-from-multi-threaded-applications for recommended settings.\n', ...
        'To disable this message, explicitly use -cc to specify an Intel compiler.']);
end

if m2c_opts.withMKL
    % When using MKL, diable BLAS and its libraries
    m2c_opts.withBlas = false;
    m2c_opts.blasLibs = {};
end
end

function build_exe(cpath, func)
command = [cpath 'build_' func '_exe.m'];

clear(command);
if exist(command, 'file'); run(command); end
end

function [PCC, CXX, INC, CFLAGS, CXXFLAGS] = obtain_petscCC(filename)
% Obtian the PCC and CXX commands from the petscvariables file
str = readFile(filename);
pat = '\nPCC\s*=\s*([^\n]+)\n';

def = regexp(str, pat, 'match', 'once');

if ~isempty(def)
    PCC = strtrim(regexprep(def, pat, '$1'));
else
    PCC = '';
end

if nargout>1
    pat = '\nCXX\s*=\s*([^\n]+)\n';
    
    def = regexp(str, pat, 'match', 'once');
    
    if ~isempty(def)
        CXX = strtrim(regexprep(def, pat, '$1'));
    else
        CXX = '';
    end
end

if nargout>2
    INC = '';
    pat = 'PETSC_CC_INCLUDES\s*=\s*([^\n]+)\n';
    def = regexp(str, pat, 'match', 'once');
    
    if ~isempty(def)
        INC = strtrim(regexprep(def, pat, '$1'));
    end
end

if nargout>3
    CFLAGS = '';
    pat = '\nCC_FLAGS\s*=\s*([^\n]+)\n';
    def = regexp(str, pat, 'match', 'once');
    
    if ~isempty(def)
        CFLAGS = strtrim(regexprep(def, pat, '$1'));
    end
end

if nargout>4
    CXXFLAGS = '';
    pat = '\CXX_FLAGS\s*=\s*([^\n]+)\n';
    def = regexp(str, pat, 'match', 'once');
    
    if ~isempty(def)
        CXXFLAGS = strtrim(regexprep(def, pat, '$1'));
    end
end
end

function str = dylibdir(dir)
if ismac; concat = ','; else concat = '='; end
str = ['-L' dir, ' -Wl,-rpath' concat dir];
end
