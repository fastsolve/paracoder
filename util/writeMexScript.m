function writeMexScript(funcname, cpath, m2c_opts)
% Generate a script for building the Mex file.

% Nested function for writing out mex script

if exist('octave_config_info', 'builtin')
    prefix = 'oct_';
else
    prefix = 'mex_';
end

if ~isequal(cpath, '.')
    outMfile = [cpath '/' prefix funcname '.m'];
end
clear(outMfile);

mexflags = '';

CC = '';
CFLAGS = '-fPIC';
LDFLAGS = '';

if m2c_opts.useCpp
    varname_CFLAGS = 'CXXFLAGS';
    varname_OPTIMFLAGS = 'CXXOPTIMFLAGS';
else
    varname_CFLAGS = 'CFLAGS';
    varname_OPTIMFLAGS = 'COPTIMFLAGS';
end

if m2c_opts.withPetsc
    % If PETSC is used, enforce using the PCC or CXX commands used in
    % PETSc for CC and add the include path.
    CC = ['CC=''''' m2c_opts.petscCC{1} '''''' ...
        ' CXX=''''' m2c_opts.petscCXX{1} ''''''];
    if m2c_opts.useCpp
        CFLAGS = [CFLAGS ' ' m2c_opts.petscCXXFLAGS{1}];
    else
        CFLAGS = [CFLAGS ' ' m2c_opts.petscCFLAGS{1}];
    end
elseif m2c_opts.withMPI
    % If MPI is used, enforce using mpi compiler wrappers
    CC = ['CC=''''' m2c_opts.mpiCC{1} ''''' CXX=''''' m2c_opts.mpiCXX{1} ''''''];
elseif isempty(m2c_opts.cc) && ismac && m2c_opts.withOMP
    % Try to locate gcc-mp, with support of OpenMP
    [CBASE, CXXBASE, found] = locate_gcc_mp;
    if ~found
        if m2c_opts.withOMP
            warning('m2c:buildEXE', 'OpenMP is disabled.');
            m2c_opts.ompLibs = {};
        end
    end
    
    CC = ['CC=''''' CBASE ''''' CXX=''''' CXXBASE ''''''];
elseif ~isempty(m2c_opts.cc)
    CC = sprintf('%s ', m2c_opts.cc{:});
end

CFLAGS = [CFLAGS ' -Wno-unused-variable -Wno-unused-function -Wno-null-character -Wno-invalid-pp-token'];
if m2c_opts.withOMP
    CFLAGS = [CFLAGS ' -fopenmp'];
    LDFLAGS = [LDFLAGS ' -fopenmp'];
end

if ismac
    LDFLAGS = [LDFLAGS ' -dynamiclib'];
end

if ~isempty(CC)
    mexflags = [mexflags ' ' CC];
end

CPPFLAGS = ' -I"'' m2cdir ''/include" ';
if ~isempty(m2c_opts.cppflags)
    CPPFLAGS = [CPPFLAGS sprintf(' %s ', m2c_opts.cppflags{:})];
end
% Append all the CPPFLAGS
mexflags = [mexflags ' ' CPPFLAGS];

if ~isempty(m2c_opts.cflags)
    % Overwrite all the CFLAGS flags
    mexflags = [mexflags ' ' varname_CFLAGS '=''''' sprintf(' %s ', m2c_opts.cflags{:}) ''''''];
elseif ~isempty(CFLAGS)
    mexflags = [mexflags ' ' varname_CFLAGS '=''''' CFLAGS ''''''];
end

if ~isempty(m2c_opts.ldflags)
    mexflags = [mexflags ' LDFLAGS=''''' sprintf(' %s ', m2c_opts.ldflags{:}) ''''''];
elseif ~isempty(LDFLAGS)
    mexflags = [mexflags ' LDFLAGS=''''' LDFLAGS ''''''];
end

if m2c_opts.optimLevel==0
    COPTFLAGS = '-O0 -DM2C_DEBUG=1';
else
    COPTFLAGS = ['-O' num2str(m2c_opts.optimLevel) ' -DNDEBUG -DM2C_DEBUG=0'];
end

if m2c_opts.withBlas
    COPTFLAGS = [COPTFLAGS ' -DM2C_BLAS=1 '];
end
if m2c_opts.withNvcc
    COPTFLAGS = [COPTFLAGS ' -DM2C_NVCC=1 '];
elseif m2c_opts.withCuda
    COPTFLAGS = [COPTFLAGS ' -DM2C_CUDA=1 '];
end
if m2c_opts.withMKL
    COPTFLAGS = [COPTFLAGS ' -DM2C_MKL=1 '];
end
if m2c_opts.withOMP
    COPTFLAGS = [COPTFLAGS ' -DM2C_OPENMP '];
end

if m2c_opts.debugInfo && m2c_opts.verbose
    COPTFLAGS = [COPTFLAGS ' -g -v'];
elseif m2c_opts.debugInfo
    COPTFLAGS = [COPTFLAGS ' -g'];
end
mexflags = [mexflags ' ' varname_OPTIMFLAGS '=''''' COPTFLAGS ''''''];

if ~isempty(m2c_opts.mexflags)
    % Overwrite mexflags
    mexflags = sprintf(' %s ', m2c_opts.mexflags{:});
end

if m2c_opts.withPetsc
    % Append mexflags using petscInc
    mexflags = [mexflags sprintf(' %s ', m2c_opts.petscInc{:})];
end
if m2c_opts.withMKL
    % Append mexflags using mklInc
    mexflags = [mexflags sprintf(' %s ', m2c_opts.mklInc{:})];
end
if m2c_opts.withCuda
    % Append mexflags using cudaInc
    mexflags = [mexflags sprintf(' %s ', m2c_opts.cudaInc{:})];
end
if m2c_opts.withMPI
    % Append mexflags using mpiInc
    mexflags = [mexflags sprintf(' %s ', m2c_opts.mpiInc{:})];
end
if m2c_opts.verbose; mexflags = [mexflags ' -v']; end
if m2c_opts.quiet; mexflags = [mexflags ' -silent']; end

libs = sprintf(' %s ', m2c_opts.libs{:});
libs = [libs sprintf(' %s ', m2c_opts.petscLibs{:})];
if m2c_opts.withMKL
    libs = [libs sprintf(' %s ', m2c_opts.mklLibs{:})];
elseif m2c_opts.withLapack
    libs = [libs sprintf(' %s ', m2c_opts.lapackLibs{:})];
elseif m2c_opts.withBlas
    libs = [libs sprintf(' %s ', m2c_opts.blasLibs{:})];
end

if m2c_opts.withCuda
    libs = [libs sprintf(' %s ', m2c_opts.cudaLibs{:})];
end

libs = [libs sprintf(' %s ', m2c_opts.mpiLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.ompLibs{:})];

libs = strtrim(libs);

if ~isempty(libs)
    LINKLIBS = [' LINKLIBS=''''$LINKLIBS  ' libs ''''''];
else
    LINKLIBS = '';
end

if m2c_opts.withNvcc
    cuda_out = [funcname '_cuda.o'];
    srcs = [funcname '.o ' cuda_out ' ' funcname '_mex.cpp'];
else
    srcs = [funcname '.' m2c_opts.suf ' ' funcname '_mex.' m2c_opts.suf];
end

if m2c_opts.enableInf
    srcs = [srcs ' rtGetInf.' m2c_opts.suf  ' rtGetNaN.' m2c_opts.suf ' rt_nonfinite.' m2c_opts.suf];
end


% Place mex file in the same directory as the M file.
mexdir = '../../../';
% If m2c_opts.mexDir is nonempty, modify the output directory.
if ~isempty(m2c_opts.mexDir)
    mexdir = [mexdir m2c_opts.mexDir{1} '/'];
end

[~, signature] = ckSignature(m2c_opts, 'mex');

% Place mex file in the same directory as the M file.
filestr = sprintf('%s\n', ...
    ['% Build script for ' funcname], signature, '', ...
    ['if exist(''isnewer'', ''file'') && ~isnewer([''' mexdir funcname ...
    '.'' mexext], ''' prefix funcname '.m'', ''' funcname '_mex.' m2c_opts.suf ''')'], ...
    '    m2cdir = fileparts(which(''m2c_printf.m''));');

if m2c_opts.withNvcc
    NVCC = [m2c_opts.cudaDir{1} '/bin/nvcc'];
    NVCC_CFLAGS = [regexprep(CFLAGS, '(-[^\s]+)', '-Xcompiler $1'), ' -m64 -arch=sm_20 '];
    cuda_out = [funcname '_cuda.o'];
    nvccCmd1 = [NVCC ' ' CPPFLAGS ' ' COPTFLAGS ' '  NVCC_CFLAGS ' -x cu -dc ' funcname '.' m2c_opts.suf ' -o ' funcname '.o'];
    nvccCmd2 = [NVCC ' ' COPTFLAGS ' '  NVCC_CFLAGS ' -dlink ' funcname '.o  -o ' cuda_out];
    
    filestr = sprintf('%s\n', filestr, ...
        ['    nvccCmd1 = [''' nvccCmd1 '''];'], ...
        ['    nvccCmd2 = ''' nvccCmd2 ''';']);
    
    if ~m2c_opts.quiet
        filestr = sprintf('%s\n', filestr, ...
            '    disp(nvccCmd1); status = unix(nvccCmd1, ''-echo'');', ...
            '    disp(nvccCmd2); status = unix(nvccCmd2, ''-echo'');');
    else
        filestr = sprintf('%s\n', ...
            '    unix(nvccCmd1);', ...
            '    unix(nvccCmd2);');
    end
end

if exist('octave_config_info', 'builtin')
    filestr = sprintf('%s\n', filestr, ...
        ['    build_cmd = [''mmex ' mexflags ' ' ...
        srcs ' -output ' mexdir funcname  '.'' mexext ''' LINKLIBS '''];']);
else
    filestr = sprintf('%s\n', filestr, ...
        ['    build_cmd = [''mex ' mexflags ' '...
        srcs ' -largeArrayDims -output ' mexdir funcname  '.'' mexext ''' LINKLIBS '''];']);
end

if ~m2c_opts.quiet
    filestr = sprintf('%s\n', filestr, ...
        '    fprintf(''Entering %s\n'', pwd);', ...
        '    disp(build_cmd);', ...
        '    eval(build_cmd);', ...
        'else', ['    fprintf(''' funcname '.%s is up to date.\n'', mexext);'], 'end');
else
    filestr = sprintf('%s\n', filestr, ...
        '    eval(build_cmd);', 'end');
end

writeFile(outMfile, filestr);
end
