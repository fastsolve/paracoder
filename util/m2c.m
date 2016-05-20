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
%     -inline
%           Enable function inlining in MATLAB Coder. This is the default
%           with -O1, -O2 and -O3, and it overwrites the value set by -O0.
%     -no-inline
%           Disable function inlining in MATLAB Coder. This is the default
%            with -O0, and it overwrites the value set by -O1, -O2, and -O3.
%     -no-inf
%     -noinf
%           Disable support of NonFinite (inf and nan). It produces faster codes.
%           This is the default.
%     -inf
%           Enable support of NonFinite (inf and nan). It produces slower codes.
%     -config 'objname'
%     -config {'expression'}
%           Use the given coder.CodeConfig object for codegen. The argument
%           is a string contained a variable or function name that evaluates
%           to a coder.CodeConfig object in the MATLAB base workspace.
%           When this option is specified, code generation is forced.
%           If string is contained in a cell array, then the string can
%           be a MATLAB expression that evaluates to a character string.
%           This overwrites the default values used by m2c, except that the
%           headers for MPI, OpenMP etc. are appended to the given CustomSourceCode.
%     -api
%     -api 'func'
%     -api {'expression1, 'expression2', ...}
%           Request m2c to generate API code to the list of functions and
%           include them in the header file. The argument list may be the
%           name of a single function or a cell array of MATLAB expressions
%           that evaluate to the names of the functions. An API function must
%           not be inlined, which can be ensured by adding coder.inline('never')
%           in the M code. Note that the top-level function is automatically
%           an API function and need not be listed. This argument can be
%           repeated, and then the functions will be concatenated.
%     -ckdep
%           By default, m2c does not regenerated C code if it already exist.
%           Use this optoin to request m2c to check the dependecies of the
%           M file and and regenerate C code if any dependence is newer.
%           This can be slow, so it should be only if you do not want to
%           use -force.
%     -cktop
%           By default, m2c does not regenerated C code if it already exist.
%           Use this optoin to request m2c to check the dependecies of the
%           top-level M file and and regenerate C code. This is much faster, 
%           than -ckdep, so it should be the default mode for most code development.
%     -force
%           Force the regeneration of C code and recompilation.
%     -skipcg
%           Skip calling codegen, even if -force, -ckdep, or -cktop is specified.
% OPTIMIZATION
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
%
% PROFILING AND INSTRUMENTATION
%     -time
%     -time 'func'
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
%     -gprof 'gprof command'
%     -gprof {'expression'}
%           Compile standalone code with profiling support and generate
%           a script to process results from gprof (Linux only).
%           The gprof command can be specified after it as a character
%           string, or a MATLAB expression contained in a cell array.
%     -gcov
%     -gcov 'gcov command'
%     -gcov {'expression'}
%           Compile standalone code with profiling support and generate
%           a script to process results from gcov (Linux and Mac).
%           The gcov command can be specified after it as a character
%           string, or a MATLAB expression contained in a cell array.
%
% DEBUGGING
%     -g
%           Preserve MATLAB code info in C code and also generate source-level
%           debug information when compiling C.
%     -ddd
%     -ddd 'ddd command'
%     -ddd {'expression'}
%           Generate a script for running the standalone executable in ddd.
%           The ddd command can be specified after it as a character
%           string, or a MATLAB expression contained in a cell array.
%     -valgrind
%     -valgrind 'valgrind command'
%     -valgrind {'expression'}
%           Generate a script for running the standalone executable in valgrind.
%           The valgrind command can be specified after it as a character
%           string, or a MATLAB expression contained in a cell array.
%
% BUILD CUSTOMIZATION
%     -cc 'c-compiler command'
%     -cc {'expression'}
%           Specify the C compiler. It overwrites the default complier
%           choice for both the mex file and the standalone executable.
%           The cc command can be specified after it as a character
%           string, or a MATLAB expression contained in a cell array.
%     -cflags {'flag1', 'flag2', ...}
%           Specify additional flags for the C compiler for building the
%           mex file and the standalone executable. The argument list
%           is a cell array of character strings. E.g.,
%           -cflags {'-O3 -NDEBUG'}. Each string can be a MATLAB expression.
%           It overwrites the default compiler flags set by -O?, -g, -gprof,
%           -gcov and any supported external libraries.
%     -mexflags {'flag1', 'flag2', ...}
%           Specify flags for the mex command. It overwrites the flags
%           assigned by -O?, -cc -cflags options. The argument
%           list is a cell array of character strings. E.g.,
%           -mexflags {'COPTIMFLAGS=''-O3 -NDEBUG'''}. Each string can be
%           a MATLAB expression.
%     -libs {'-Ldir1', '-llib1', '-llib2', ...}
%           Specify additional libraries for linker when building both
%           the mex file and the standalone executable. The argument list
%           is a cell array of character strings. E.g.,
%           -libs {'-L/opt/local/lib', '-llapack'}. Each string can be
%           a MATLAB expression. They will be listed before the libraries
%           required by the supported external libraries.
%
% SUPPORTED EXTERNAL LIBRARIES
%     -mpi
%     -mpi {'-Ldir1', '-llib1', '-llib2', ...}
%           Enable support for MPI. The argument list is a cell array of
%           character strings to be passed to the C compiler and linker.
%           Each string can be a MATLAB expression. It requires MMPI.
%     -omp
%     -omp {'-Ldir1', '-llib1', '-llib2', ...}
%           Enable support for OpenMP. The argument list is a cell array of
%           character strings to be passed to the C compiler and linker.
%           Each string can be a MATLAB expression. It requires MACC.
%     -acc
%     -acc {'-Ldir1', '-llib1', '-llib2', ...}
%           Enable support for OpenACC. The argument list is a cell array of
%           character strings to be passed to the C compiler and linker.
%           Each string can be a MATLAB expression. It requires MACC.
%     -petsc
%     -petsc 'petsc-directory'
%     -petsc {'expression'}
%           Enable support for PETSc. The root directory of PETSc can be
%           specified as a character string, or a MATLAB expression
%           contained in a cell array. The default path can be extracted
%           from the environment variables PETSC_DIR and PETSC_ARCH.
%     -lapack
%     -lapack {'-Ldir1', '-llib1', '-llib2', ...}
%           Enable LAPACKE and link with the LAPACK library specified in
%           the list. The argument list is a cell array of character strings
%           to be passed to the C compiler and linker. Each string can be
%           a MATLAB expression. If the cell array is empty, then the
%           MATLAB built-in LAPACK library will be used.
%     -efence
%     -efence {'-Ldir1', '-llib1', '-llib2', ...}
%           Link the standalone executable with electric-fence for
%           debugging memory errors. The argument list is a cell array of
%           character string to be passed to the linker, such as
%  	        -efence {'-L/usr/local/lib', '-lefence'}. Each string can be
%           a MATLAB expression. It is most useful in conjunction with
%           a debugger, such as ddd, for debugging segmentation faults.
%
% MISCELLANEOUS
%     -mex
%           Build the mex command in addition to generating the C files.
%     -mexdir {'relative_path_to_m_file'}
%           Save the mex file to the directory given by the path relative
%           to the M file. By default, the mex files will be saved in the
%           same directory as the M file.
%     -exe
%           Generate a MATLAB script for running the exe file from within
%           MATLAB for debugging in place of the M-file (Linux and Mac).
%     -exedir {'relative_path_to_m_file'}
%           Save the exe file into the directory given by the path relative
%           to the M file. By default, the exe fileswill be saved in the
%           same directory as the M file.
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

%% Set default values for inline, force and genExe
if isempty(m2c_opts.enableInline)
    m2c_opts.enableInline = m2c_opts.optLevel ~= '0';
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

% Determine whether to include mpi.h
if m2c_opts.withMPI
    mpi_header = '#include "mpi.h"';
else
    mpi_header = '';
end

% Determine whether to include omp.h
if m2c_opts.withOMP
    acc_header = '#include "omp.h"';
elseif m2c_opts.withACC
    acc_header = '#include "openacc.h"';
else
    acc_header = '';
end

if m2c_opts.withPetsc
    petsc_header = '#include "mpetsc.h"';
else
    petsc_header = '';
end

regen_c = ~m2c_opts.skipcg && (m2c_opts.force || ~exist([cpath  func '.c'], 'file') || ...
    ~exist([cpath  func '_mex.c'], 'file') || ...
    ~ckSignature(m2c_opts, 'codegen', [cpath  func '_mex.c']) || ...
    m2c_opts.cktop && ~isnewer([cpath  func '_mex.c'], mfile) || ...
    m2c_opts.ckdep && ~ckdep([cpath  func '.c'], mfile, true));

if regen_c
    % Determine whether you have codegen.
    if ~exist('codegen.p', 'file')
        error('m2c:MissingCoder', 'MATLAB Coder is required to generate C code.');
    end
    
    if ~isempty(m2c_opts.codegenConfig)
        co_cfg = evalin('base', sprintf('%s', m2c_opts.codegenConfig{1}));
        
        if isempty(co_cfg) || ~isa(co_cfg, 'coder.CodeConfig')
            error('m2c:WrongArgument', ['The argument after -config must evaluate to a coder.CodeConfig ' ...
                'object. Received %s Use command coder.config(''lib'') to create the object'], ...
                m2c_opts.codegenConfig{1});
        end
    else
        %% Specify codegen config options
        co_cfg = coder.config('lib');
        
        co_cfg.SaturateOnIntegerOverflow = false;
        co_cfg.EnableVariableSizing = true;
        cfg.PassStructByReference = true;
        co_cfg.EnableMemcpy = true;
        
        co_cfg.DynamicMemoryAllocation = 'AllVariableSizeArrays';
        co_cfg.FilePartitionMethod = 'SingleFile';
        
        co_cfg.GenerateMakefile = false;
        co_cfg.GenCodeOnly = true;
        co_cfg.GenerateReport = true;
        co_cfg.InitFltsAndDblsToZero = false;
        co_cfg.SupportNonFinite = m2c_opts.enableInf;
        
        if m2c_opts.useCpp
            co_cfg.TargetLang = 'C++';
            m2c_opts.suf = 'cpp';
        else
            co_cfg.TargetLang = 'C';
            m2c_opts.suf = 'c';
        end
        
        try co_cfg.CustomSymbolStrTmpVar = '$M$N';
        catch; end
        try co_cfg.MultiInstanceCode = true;
        catch; end
        try co_cfg.GenerateComments = m2c_opts.debugInfo;
        catch; end
        try co_cfg.MATLABFcnDesc = m2c_opts.debugInfo;
        catch; end
        try co_cfg.MATLABSourceComments = m2c_opts.debugInfo;
        catch; end
        try co_cfg.PassStructByReference = true;
        catch; end
        
        if m2c_opts.withLapack
            try co_cfg.CustomLAPACKCallback = 'useBuiltinLAPACK';
            catch; end %#ok<CTCH>
        end
    end
    
    warning('off', 'CoderFoundation:builder:TMFIncompatibilityWarningMATLABCoder');
    if isequal(co_cfg.TargetLang, 'C++')
        warning('C++ code generation is not supported. Use at your own risk.');
    end
    
    co_cfg.CustomSourceCode = sprintf('%s\n', co_cfg.CustomSourceCode, ...
        mpi_header, acc_header, petsc_header, '#include "m2c.h"');
    
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
    command = strtrim([basecommand ' ' opts ' ' func ' ' m2c_opts.codegenArgs]);
    
    try
        if exist('./codegen', 'dir'); addpath ./codegen; end
        disp(command)
        eval(command);
        path(p); cd(olddir);
    catch err
        path(p); cd(olddir);
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
    if exist([cpath 'examples'], 'dir'); rmdir([cpath 'examples'], 's'); end
    if exist([cpath 'interface'], 'dir'); rmdir([cpath 'interface'], 's'); end
end

%% Generate MATLAB scripts for mex
if regen_c || m2c_opts.force || ~ckSignature(m2c_opts, 'mex', [cpath  'mex_' func '.m'])
    writeMexScript(func, cpath, m2c_opts);
end

if m2c_opts.genMex 
    run_mexcommand(cpath, func);
elseif m2c_opts.verbose
    fprintf('To build the MEX file, use command (without quotes): "run %s".\n', ...
        [cpath 'mex_' func '.m']);
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
    
    build_exe(cpath, func);
    if m2c_opts.verbose
        fprintf(['To run the EXE file in MATLAB, ', ...
            'replace calls to ' func ' by run_' func '_exe.\n']);
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
m2c_opts = struct('codegenArgs', '', ...
    'codegenConfig', [], ...
    'debugInfo', false, ...
    'enableInline', [], ...
    'optLevel', '0', ...
    'enableInf', false, ...
    'api', [], ...
    'timing', [], ...
    'cc', [], ...
    'libs', [], ...
    'cflags', [], ...
    'mexflags', [], ...
    'withMPI', false, ...
    'mpiCC', [], ...
    'mpiCXX', [], ...
    'mpiLibs', [], ...
    'withOMP', false, ...
    'ompLibs', [], ...
    'withACC', false, ...
    'accLibs', [], ...
    'withLapack', false, ...
    'lapackLibs', [], ...
    'withPetsc', false, ...
    'petscDir', [], ...
    'petscCC', [], ...
    'petscCXX', [], ...
    'petscCFLAGS', [], ...
    'petscCXXFLAGS', [], ...
    'petscInc', [], ...
    'petscLibs', [], ...
    'gprof', [], ...
    'gcov', [], ...
    'valgrind', [], ...
    'ddd', [], ...
    'efenceLibs', [], ...
    'genMex', false, ...
    'mexDir', [], ...
    'genExe', false, ...
    'exeDir', [], ...
    'useCpp', false, ...
    'verbose', false, ...
    'quiet', false, ...
    'suf', 'c', ...
    'force', false, ...
    'ckdep', false, ...
    'cktop', false, ...
    'skipcg', false, ...
    'gen64', false);

% Locate -args in the argument
func_index = length(varargin);
for i=1:length(varargin)
    if isequal(varargin{i}, '-args')
        func_index = i-1;
        break;
    end
end

if func_index>=1 && exist(varargin{func_index}, 'file')
    func = varargin{func_index};
else
    error('m2c:InvalidFileName', 'Function %s could not be found.', varargin{func_index});
end
m2c_opts.codegenArgs = strtrim(sprintf(' %s', varargin{func_index+1:end}));

i = 1;
last_index = func_index-1;
while i<=last_index
    switch varargin{i}
        case '-force'
            m2c_opts.force = true;
        case '-ckdep'
            m2c_opts.ckdep = true;
        case '-cktop'
            m2c_opts.cktop = true;
        case '-skipcg'
            m2c_opts.skipcg = true;
        case '-mex'
            m2c_opts.genMex = true;
        case '-exe'
            m2c_opts.genExe = true;
        case {'-mexdir', '-exedir'}
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.([varargin{i}(2:4) 'Dir']) = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.([varargin{i}(2:4) 'Dir']) = varargin(i+1);
                i = i + 1;
            else
                error('m2c:wrong_argument', ...
                    'Argument %s requires a cell-array argument after it.', varargin{i});
            end
        case '-g'
            m2c_opts.debugInfo = true;
        case '-O0'
            m2c_opts.optLevel = '0';
        case '-O1'
            m2c_opts.optLevel = '1';
        case {'-O2', '-O'}
            m2c_opts.optLevel = '2';
        case '-O3'
            m2c_opts.optLevel = '3';
        case '-inline'
            m2c_opts.enableInline = true;
        case '-no-inline'
            m2c_opts.enableInline = false;
        case {'-noinf', '-no-inf'}
            m2c_opts.enableInf = false;
        case '-inf'
            m2c_opts.enableInf = true;
        case '-time'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.timing = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.timing = varargin(i+1);
                i = i + 1;
            else
                m2c_opts.timing = {''};
            end
        case '-api'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.api = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.api = varargin(i+1);
                i = i + 1;
            else
                m2c_opts.api = {''};
            end
        case '-efence'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.efenceLibs = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.efenceLibs = varargin(i+1);
                i = i + 1;
            elseif isfield(defaultValues, varargin{i}(2:end))
                m2c_opts.efenceLibs = {'-lefence'};
            end
        case {'-valgrind', '-ddd', '-gprof', '-gcov'}
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.(varargin{i}(2:end)) = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.(varargin{i}(2:end)) = varargin(i+1);
                i = i + 1;
            else
                m2c_opts.(varargin{i}(2:end)) = {''};
            end
        case {'-cc', '-libs', '-mexflags', '-cflags'}
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.(varargin{i}(2:end)) = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.(varargin{i}(2:end)) = varargin(i+1);
                i = i + 1;
            else
                error('m2c:wrong_argument', ...
                    'Argument %s requires a cell-array argument after it. Ignored', varargin{i});
            end
        case '-lapack'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.lapackLibs = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.lapackLibs = varargin(i+1);
                i = i + 1;
            else
                m2c_opts.lapackLibs = {'-lmwlapack', '-lmwblas'};
            end
            m2c_opts.withLapack = true;
        case '-petsc'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.petscDir = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.petscDir = varargin(i+1);
                i = i + 1;
            else
                if ~isempty(getenv('PETSC_DIR')) && ~isempty(getenv('PETSC_ARCH'))
                    m2c_opts.petscDir = {[getenv('PETSC_DIR') '/' getenv('PETSC_ARCH')]};
                elseif ~isempty(getenv('PETSC_DIR'))
                    m2c_opts.petscDir = {getenv('PETSC_DIR')};
                else
                    error('m2c:petsc_dir', ...
                        ['Root directory of PETSc must be given after the ' ...
                        '-petsc flag or be specified by environment variable PETSC_DIR.']);
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
                    'PETSc must be built as a shared library in order to be used in MATLAB. ');
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
            
            mpetscInc = [fileparts(which('mptSolve.m')), '/include'];
            m2c_opts.petscInc = {[INC ' -I' mpetscInc]};

            if ismac; concat = ','; else concat = '='; end
            m2c_opts.petscLibs = {['-L' m2c_opts.petscDir{1} '/lib', ...
                ' -Wl,-rpath' concat m2c_opts.petscDir{1} '/lib'], '-lpetsc'};
            m2c_opts.withPetsc = true;
        case {'-mpi'}
            m2c_opts.withMPI= true;
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.mpiLibs = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.mpiLibs = varargin(i+1);
                i = i + 1;
            else
                m2c_opts.mpiLibs = {''};
            end
            
            if ~isempty(m2c_opts.petscCC)
                petsc_opts = m2c_opts;
            else
                petsc_opts = proc_options('-petsc', func);
            end
            if ~isempty(petsc_opts.petscCC)
                m2c_opts.mpiCC = petsc_opts.petscCC;
                m2c_opts.mpiCXX = petsc_opts.petscCXX;
            else
                m2c_opts.mpiCC = {'mpicc'};
                m2c_opts.mpiCXX = {'mpicc'};
            end
        case {'-omp', '-acc'}
            m2c_opts.(['with' upper(varargin{i}(2:end))])= true;
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.([varargin{i}(2:end) 'Libs']) = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.([varargin{i}(2:end) 'Libs']) = varargin(i+1);
                i = i + 1;
            else
                m2c_opts.([varargin{i}(2:end) 'Libs']) = {''};
            end
        case '-config'
            if i<last_index && varargin{i+1}(1) == '{'
                m2c_opts.codegenConfig = eval(varargin{i+1});
                i = i + 1;
            elseif i<last_index && varargin{i+1}(1) ~= '-'
                m2c_opts.codegenConfig = varargin(i+1);
                i = i + 1;
            else
                error('m2c:wrong_argument', ...
                    'Argument %s requires a cell-array argument after it. Ignored', varargin{i});
            end
        case '-v'
            m2c_opts.verbose = true;
        case '-q'
            m2c_opts.quiet = true;
        case '-m'
            warning('Option -m is suppresed.');
        case '-64'
            m2c_opts.gen64 = true;
            warning('Option -64 is suppresed and no longer supported.');
        case '-c++'
            m2c_opts.useCpp = true;
            warning('Option -c++ is suppresed and no longer supported.');
        case {'-h', '-?', '--help'}
            m2c_opts = [];
            return;
        otherwise
            error('m2c:wrong_argument', ...
                'Unrecognized argument %s.', varargin{i});
    end
    i = i +1;
end

names = fieldnames(m2c_opts);
for i=1:length(names)
    if isempty(m2c_opts.(names{i})) && ~ischar(m2c_opts.(names{i}))
        m2c_opts.(names{i}) = {};
    end
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
    pat = '\PETSC_CC_INCLUDES\s*=\s*([^\n]+)\n';
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
