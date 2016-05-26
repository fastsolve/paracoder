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
CFLAGS = '';

if m2c_opts.withPetsc
    % If PETSC is used, enforce using the PCC or CXX commands used in
    % PETSc for CC and add the include path.
    CC = ['CC=''''' m2c_opts.petscCC{1} '''''' ...
        ' CXX=''''' m2c_opts.petscCXX{1} ''''''];
    if m2c_opts.useCpp
        CFLAGS = [' CXXFLAGS=''''' m2c_opts.petscCXXFLAGS{1} ...
            ' -Wno-unused-variable -Wno-unused-function'''''];
    else
        CFLAGS = ['CFLAGS=''''' m2c_opts.petscCFLAGS{1} ...
            ' -Wno-unused-variable -Wno-unused-function'''''];
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

if ~isempty(CC)
    mexflags = [mexflags ' ' CC];
end
if ~isempty(CFLAGS)
    mexflags = [mexflags ' ' CFLAGS];
end

switch m2c_opts.optLevel
    case '0'
        coptflags = ['-O' m2c_opts.optLevel ' -DM2C_DEBUG=1'];
    case {'1','2','3'}
        coptflags = ['-O' m2c_opts.optLevel ' -DNDEBUG -DM2C_DEBUG=0'];
    otherwise
        coptflags = '';
end

if m2c_opts.useCpp
    mexflags = [mexflags ' CXXOPTIMFLAGS=''''' coptflags ''''''];
    if m2c_opts.debugInfo;
        mexflags = [mexflags ' CXXDEBUGFLAGS=''''-g'''''];
    end
else
    mexflags = [mexflags ' COPTIMFLAGS=''''' coptflags ''''''];
    if m2c_opts.debugInfo;
        mexflags = [mexflags ' CDEBUGFLAGS=''''-g'''' '];
    end
end

if ~isempty(m2c_opts.cflags) && m2c_opts.useCpp
    % Overwrite all the C flags
    mexflags = [mexflags ' CXXFLAGS=''''' sprintf(' %s ', m2c_opts.cflags{:}) ''''''];
elseif ~isempty(m2c_opts.cflags)
    % Overwrite all the C flags
    mexflags = [mexflags ' CFLAGS=''''' sprintf(' %s ', m2c_opts.cflags{:}) ''''''];
end

if ~isempty(m2c_opts.mexflags)
    % Overwrite mexflags
    mexflags = sprintf(' %s ', m2c_opts.mexflags{:});
end

if m2c_opts.withPetsc
    % Append mexflags using petscInc
    mexflags = [mexflags sprintf(' %s ', m2c_opts.petscInc{:})];
end
if m2c_opts.withMPI
    % Append mexflags using mpiInc
    mexflags = [mexflags sprintf(' %s ', m2c_opts.mpiInc{:})];
end
if m2c_opts.verbose; mexflags = [mexflags ' -v']; end
if m2c_opts.quiet; mexflags = [mexflags ' -silent']; end

libs = sprintf(' %s ', m2c_opts.libs{:});
libs = [libs sprintf(' %s ', m2c_opts.lapackLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.mpiLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.ompLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.accLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.petscLibs{:})];

libs = strtrim(libs);

if ~isempty(libs)
    LINKLIBS = [' LINKLIBS=''''$LINKLIBS  ' libs ''''''];
else
    LINKLIBS = '';
end

srcs = [funcname '.' m2c_opts.suf ' ' funcname '_mex.' m2c_opts.suf];
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

if exist('octave_config_info', 'builtin')
    filestr = sprintf('%s\n', filestr, ...
        ['    build_cmd = [''mmex ' mexflags ' -I"'' m2cdir ''/include" '...
        srcs ' -output ' mexdir funcname  '.'' mexext ''' LINKLIBS '''];']);
else
    filestr = sprintf('%s\n', filestr, ...
        ['    build_cmd = [''mex ' mexflags ' -I"'' m2cdir ''/include" '...
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
