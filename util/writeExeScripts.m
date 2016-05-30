function writeExeScripts(funcname, cpath, m2c_opts)
% Generate scripts for building the standalone executable.

altapis = [funcname, strtrim(strrep(regexp(m2c_opts.codegenArgs, '(\w+)\s+-args', 'match'), ' -args', ''))];

if ~isequal(cpath, '.')
    outMfile = [cpath 'build_' funcname '_exe.m'];
end
clear(outMfile);

if m2c_opts.withPetsc
    % If PETSC is used, enforce using the PCC or CXX commands used in
    % PETSc for CC, and add the include path and libraries.
    if m2c_opts.useCpp
        CC = m2c_opts.petscCXX{1};
    else
        CC = m2c_opts.petscCC{1};
    end
elseif m2c_opts.withMPI
    % If MPI is used, enforce using mpi compiler wrappers
    if m2c_opts.useCpp
        CC = ['CXX=''''' m2c_opts.mpiCXX{1} ''''''];
    else
        CC = ['CC=''''' m2c_opts.mpiCC{1} ''''''];
    end
elseif m2c_opts.withACC
    % Try to locate pgcc, with support of OpenACC and OpenMP
    [CBASE, CXXBASE, found] = locate_pgcc;
    if ~found
        error('Could not locate pgcc. Please disable openacc');
    end
    
    if m2c_opts.useCpp
        CC = CXXBASE;
    else
        CC = CBASE;
    end
elseif isempty(m2c_opts.cc)
    if m2c_opts.useCpp
        CC = 'g++';
    else
        CC = 'gcc';
    end
    
    if ismac && m2c_opts.withOMP
        % Try to locate gcc-mp, with support of OpenMP
        [CC, CXX, found] = locate_gcc_mp;
        
        if ~found
            if m2c_opts.ompLibs
                warning('m2c:buildEXE', 'OpenMP is disabled.');
                m2c_opts.ompLibs = {};
            end
        elseif m2c_opts.useCpp
            CC = CXX;
        end
    end
else
    CC = sprintf(' %s ', m2c_opts.cc{:});
end

switch m2c_opts.optLevel
    case '0',
        cflags = ['-O' m2c_opts.optLevel ' -DM2C_DEBUG=1 -g'];
    case {'1','2','3'}
        cflags = ['-O' m2c_opts.optLevel ' -DNDEBUG -DM2C_DEBUG=0 -g'];
    otherwise
        cflags = '-g';
end

if ~m2c_opts.withACC
    if m2c_opts.withOMP
        cflags = [cflags ' -fopenmp'];
    end
    cflags = [cflags '  -Wall -Wno-unused-variable -Wno-unused-function'];
end

if m2c_opts.withACC
    % Currently only supports PGI compilers
    cflags = [cflags ' -acc -fast -ta=nvidia:cc30'];
    if m2c_opts.debugInfo
        cflags = [cflags ' -Minfo=accel'];
    end
end

if ~isempty(m2c_opts.gprof)
    cflags = [cflags ' -pg '];
elseif ~isempty(m2c_opts.gcov)
    cflags = [cflags ' -fprofile-arcs -ftest-coverage -fPIC '];
    try delete([cpath '*.gcda']); catch; end
    try delete([cpath '*.gcno']); catch; end
end

if ~isempty(m2c_opts.cflags)
    % Overwrite cflags
    cflags = sprintf(' %s ', m2c_opts.cflags{:});
end
if ~isempty(m2c_opts.cppflags)
    cppflags = sprintf(' %s ', m2c_opts.cppflags{:});
else
    cppflags = '';
end
if m2c_opts.withBlas
    cppflags = [cppflags ' -DM2C_BLAS=1 '];
end
if m2c_opts.withCuda
    cppflags = [cppflags ' -DM2C_CUDA=1 '];
end
if m2c_opts.withOMP
    cppflags = [cppflags ' -DM2C_OPENMP '];
end
if m2c_opts.withACC
    cppflags = [cppflags ' -DM2C_OPENACC '];
end

if m2c_opts.withPetsc
    % Append petscInc to cflags
    cflags = [cflags sprintf(' %s ', m2c_opts.petscInc{1})];
end
if m2c_opts.withCuda
    % Append petscInc to cflags
    cflags = [cflags sprintf(' %s ', m2c_opts.cudaInc{1})];
end
if m2c_opts.withMPI
    % Append mpiInc to cflags
    cflags = [cflags sprintf(' %s ', m2c_opts.mpiInc{1})];
end

if m2c_opts.verbose; cflags = ['-v ' cflags]; end

libs = sprintf(' %s ', m2c_opts.libs{:});
libs = [libs sprintf(' %s ', m2c_opts.efenceLibs{:})];
if m2c_opts.withLapack
    libs = [libs sprintf(' %s ', m2c_opts.lapackLibs{:})];
elseif m2c_opts.withBlas
    libs = [libs sprintf(' %s ', m2c_opts.blasLibs{:})];
end
if m2c_opts.withCuda
    libs = [libs sprintf(' %s ', m2c_opts.cudaLibs{:})];
end
libs = [libs sprintf(' %s ', m2c_opts.mpiLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.ompLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.accLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.petscLibs{:})];

% Place exe file in the same directory as the M file.
exedir = '../../../';
% If m2c_opts.exeDir is nonempty, modify the output directory.
if ~isempty(m2c_opts.exeDir)
    exedir = [exedir m2c_opts.exeDir{1} '/'];
end

[~, signature] = ckSignature(m2c_opts, 'exe');

filestr = sprintf('%s\n', ...
    ['% Build script for ' funcname], signature, '', ...
    ['if exist(''isnewer'', ''file'') && ~isnewer(''' exedir funcname '.exe'', ''build_' funcname '_exe.m'', ''' funcname '_exe.' m2c_opts.suf ''')'], ...
    '    m2cdir = fileparts(which(''m2c_printf.m''));');

srcs = [funcname '.' m2c_opts.suf ' ' funcname '_mex.' m2c_opts.suf ' ' funcname '_exe.' m2c_opts.suf];
if m2c_opts.enableInf
    srcs = [srcs ' rtGetInf.' m2c_opts.suf  ' rtGetNaN.' m2c_opts.suf ' rt_nonfinite.' m2c_opts.suf];
end

filestr = sprintf('%s\n', filestr, ...
    '    incdir = [matlabroot ''/extern/include''];', ...
    '    bindir = [matlabroot ''/bin/'' lower(computer)];', ...
    '    if isequal(computer, ''MACI64'')', ...
    '        matlibs = [''-L'' bindir '' -Wl,-rpath,'' bindir '' -lmat -lmx -lm''];', ...
    '    elseif isequal(computer, ''GLNXA64'')', ...
    '        matlibs = [''-L'' bindir '' -Wl,-rpath='' bindir '' -lmat -lmx -lm''];', ...
    '    else', ...
    '        error(''Building executable is not supported on %s\n'', computer);', ...
    '    end', ...
    ['    build_cmd = [''' CC ' ' cppflags cflags ' -DBUILD_MAT -I"'' incdir ''" -I"'' m2cdir ''/include" '...
    srcs ' -o ' exedir funcname '.exe '  libs '''  matlibs];']);

if ~m2c_opts.quiet
    filestr = sprintf('%s\n', filestr, ...
        '    fprintf(''Entering %s\n'', pwd);', ...
        '    disp(build_cmd);', ...
        '    system(build_cmd, ''-echo'');', ...
        'else', ['    fprintf(''' funcname '.exe is up to date.\n'');'], 'end');
else
    filestr = sprintf('%s\n', filestr, ...
        '    system(build_cmd, ''-echo'');', 'end');
end

% Nested function for writing out mex script
writeFile(outMfile, filestr);

% Write M-file wrapper function for calling EXE within MATLAB
writeExeMWrapper(altapis, cpath, exedir, funcname, m2c_opts, CC);

end

function writeExeMWrapper(altapis, cpath, exedir, funcname, m2c_opts, CC)
% Generate M-file for reading and writing output through MAT files.

outfile = [cpath exedir 'run_' funcname '_exe.m'];

% Backup file
if (exist(outfile, 'file'))
    copyfile(outfile, [outfile '.bak']);
end

filestr = sprintf('%s\n', ...
    ['function varargout = run_' funcname '_exe(varargin)'], ...
    '% Invoke EXE file by passing variables through MAT files.', '',...
    'tmpdir = getenv(''TMPDIR'');', ...
    'if isempty(tmpdir); tmpdir = ''/tmp/''; else tmpdir = [tmpdir ''/'']; end', '', ...
    'suf = [''_'' num2str(feature(''getpid'')) ''.mat''];', ...
    ['infile = [tmpdir ''' funcname '_in'' suf];'], ...
    ['outfile = [tmpdir ''' funcname '_out'' suf];'], '', ...
    ['mdir = fileparts(which(''run_' funcname '_exe.m''));'], ...
    'if isequal(mdir, pwd); mdir = ''./''; else mdir = [mdir ''/'']; end', '', ...
    '% Delete MAT files', ...
    'if exist(infile, ''file''); delete(infile); end', ...
    'if exist(outfile, ''file''); delete(outfile); end', ...
    '% Export input arguments into MAT file', ...
    'm = matfile(infile, ''Writable'', true);', '', ...
    'for i=1:nargin', ...
    '    try', ...
    '        m.([''input_'' int2str(i)]) = varargin{i};', ...
    '    catch', ...
    '        clear(''m'');', ...
    '        error([''Failed to write out input variable '' int2str(i)]);', ...
    '    end', ...
    'end');

echo = ', ''-echo''';
cmdpre = '';

if ~isempty(m2c_opts.ddd)
    ddd = strtrim(sprintf(' %s ', m2c_opts.ddd{:}));
    if isempty(ddd)
        % Find ddd
        ddd = locate_ddd();
        
        % Find gdb
        gdb = locate_gdb();
        
        if ~isempty(gdb) && ~isempty(ddd)
            % Add breakpoints
            breakponts = sprintf(' -ex "break %s" ', altapis{:});
            
            cmdpre = [ddd ' --debugger ''''' gdb breakponts ' -ex run -ex where'''' --args '];
        end
        echo = '';
    end
elseif ~isempty(m2c_opts.valgrind)
    valgrind = strtrim(sprintf(' %s ', m2c_opts.valgrind{:}));
    
    if isempty(valgrind)
        valgrind = locate_valgrind();
    end
    % See http://valgrind.org/docs/manual/manual-core.html for documentation
    % Other useful options include --partial-loads-ok=yes --track-origins=yes
    cmdpre = [valgrind ' --leak-check=summary --show-possibly-lost=no --gen-suppressions=all ' ...
        '--suppressions=' fileparts(which('m2c.m')) '/' 'valgrind.supp '];
    echo = ', ''-echo''';
end

exefile = [''' mdir ''' funcname '.exe'];

filestr = sprintf('%s\n', filestr, ...
    '% Call executable using the system command', ...
    ['cmd = [''' cmdpre ' ' exefile ' '' ...'], ...
    '       int2str(nargin) '' '' infile '' '' int2str(nargout) '' '' outfile '' ''];');

if isempty(cmdpre)
    filestr = sprintf('%s\n', filestr, ...
        'fprintf(1, ''Running command "%s" ...\n'', strtrim(cmd)); tic;', ...
        ['[status,~] = system(cmd' echo ');'], ...
        'if status', ...
        ['    error(''' funcname '.exe failed'');'], ...
        'else', ...
        ['fprintf(1, ''Excutable ' funcname ' completed in %g seconds.\n'', toc);'], ...
        'end');
else
    filestr = sprintf('%s\n', filestr, 'disp(cmd);', ...
        ['[~,~] = system(cmd' echo ');']);
end

filestr = sprintf('%s\n', filestr, ...
    '% Import output arguments from MAT file', ...
    'varargout = cell(1, nargout);', ...
    'm = matfile(outfile, ''Writable'', false);', '', ...
    'for i=1:nargout', ...
    '    try', ...
    '        varargout{i} = m.([''output_'' int2str(i)]);', ...
    '    catch', ...
    '        clear(''m'');', ...
    '        error([''Failed to read in output variable '' int2str(i)]);', ...
    '    end', ...
    'end', '', ...
    '% Delete MAT files', ...
    'clear(''m'');', ...
    'if exist(infile, ''file''); delete(infile); end', ...
    'if exist(outfile, ''file''); delete(outfile); end');

if ~isempty(m2c_opts.gprof)
    gprof = strtrim(sprintf(' %s ', m2c_opts.gprof{:}));
    if isempty(gprof)
        % Find command for gprof
        gprof = locate_gprof();
    end
    
    filestr = sprintf('%s\n', filestr, ...
        '% Process gprof results', ...
        'if exist(''gmon.out'', ''file'')', ...
        ['    [~, result] = system(''' gprof ' --brief --flat-profile=' funcname '.' m2c_opts.suf ' ' funcname '.exe gmon.out'');'], ...
        '    cells = strsplit(result, ''\n'');', ...
        '    fprintf(''            Function Flat Profile (top 10):\n'');', ...
        '    fprintf(''%s\n'', cells{3:min(length(cells),14)});', ...
        ['    [~, result] = system(''' gprof ' -l --brief --flat-profile=' funcname '.' m2c_opts.suf ' ' funcname '.exe gmon.out'');'], ...
        '    cells = strsplit(result, ''\n'');', ...
        '    fprintf(''            Line-by-Line Flat Profile (top 30):\n'');', ...
        '    fprintf(''%s\n'', cells{3:min(length(cells),34)});', ...
        'else', ...
        '    fprintf(''Did not find valid profiling file gmon.out.\n'');', ...
        'end');
end

if ~isempty(m2c_opts.gcov)
    gcov = strtrim(sprintf(' %s ', m2c_opts.gcov{:}));
    
    if isempty(gcov)
        % Try to use gcov matching the version of gcc
        [pathstr,name,ext] = fileparts(CC);
        if isempty(pathstr)
            if m2c_opts.useCpp
                gcov = strrep(CC, 'g++', 'gcov');
            else
                gcov = strrep(CC, 'gcc', 'gcov');
            end
        else
            if m2c_opts.useCpp
                gcov = [pathstr '/' strrep(name, 'g++', 'gcov') ext];
            else
                gcov = [pathstr '/' strrep(name, 'gcc', 'gcov')  ext];
            end
        end
        
        if ~exist(gcov, 'file')
            gcov = locate_gcov();
        end
    end
    
    filestr = sprintf('%s\n', filestr, ...
        '% Process code coverage results', ...
        ['if exist(''' cpath  funcname '.gcda'', ''file'')'], ...
        ['    system('' cd ' cpath '; ' gcov ' -b -c ' funcname '.' m2c_opts.suf ''');'], ...
        ['    fprintf(''Openning up code coverage ' cpath '/' funcname '.' m2c_opts.suf '.gcov for ' funcname 'in editor.\n'');'], ...
        ['    edit(''' cpath funcname '.' m2c_opts.suf '.gcov'');'], ...
        'else', ...
        ['    fprintf(''Did not find valid profiling file ' cpath funcname '.gcda.\n'');'], ...
        'end');
end

filestr = sprintf('%s\n', filestr, 'end');

writeFile(outfile, filestr);

end

function [valgrind, found] = locate_valgrind
% Find valgrind
valgrind = 'valgrind';

[status, ~] = system('which valgrind');
if status
    paths = {'/opt/local/bin', '/usr/local/bin', '/sw/bin'};
    i = 1;
    while status && i<=length(paths)
        [status, result] = system(['ls ' paths{i} '/valgrid-*']);
        i = i + 1;
    end
    
    if status
        warning('m2c:buildEXE', ['Could not locate valgrind in system directories.\n' ...
            'Please install valgrind and add it to your path.']);
        valgrind = '';
        found = false;
    else
        commands = strsplit(result);
        valgrind = commands{1};
        found = true;
    end
end

if ismac && ~isempty(valgrind)
    [~, result] = system([valgrind ' --version']);
    vers = strsplit(result(10:end-1), '.');
    vers = [str2double(vers{1}) str2double(vers{2}) str2double(vers{3})];
    if vers(1) < 3 || vers(1) == 3 && vers(2) <= 11 || vers(1) == 3 && vers(2) == 11 && vers(3) == 0
        warning('m2c:buildEXE', [result(1:end-1) ' may fail on Mac OS X 10.11 El Capitan.\n', ...
            '(See https://bugs.kde.org/show_bug.cgi?id=354883).']);
    end
end
end

function [ddd, found] = locate_ddd
ddd = 'ddd';

[status, ~] = system('which ddd');
if status
    paths = {'/opt/local/bin', '/usr/local/bin', '/sw/bin'};
    i = 1;
    while status && i<=length(paths)
        [status, result] = system(['ls ' paths{i} '/ddd']);
        i = i + 1;
    end
    
    if status
        warning('m2c:buildEXE', ['Could not locate ddd in system directories.\n' ...
            'Please install ddd and add it to your path.']);
        ddd = '';
        found = false;
    else
        commands = strsplit(result);
        ddd = commands{1};
        found = true;
    end
end
end

function [gdb, found] = locate_gdb
% Locate gdb in system directory
gdb = 'gdb';
[status, ~] = system('which gdb');
if status
    files = {'/opt/local/bin/ggdb', '/opt/local/bin/gdb', ...
        '/usr/local/bin/gdb', '/sw/bin/gdb'};
    i = 1;
    while status && i<=length(files)
        [status, result] = system(['ls ' files{i}]);
        i = i + 1;
    end
    
    if status
        warning('m2c:buildEXE', ['Could not locate gdb in system directories.\n' ...
            'Please install gdb and add it to your path.']);
        gdb = '';
        found = false;
    else
        commands = strsplit(result);
        gdb = commands{1};
        found = true;
    end
end
end

function [gprof, found] = locate_gprof
% Try to locate gprof in system directory
if ismac
    warning('m2c:buildEXE', 'gprof may not work on Mac.\n');
end

gprof = 'gprof';

[status, ~] = system('which gprof');
if status
    paths = {'/opt/local/bin', '/usr/local/bin', '/sw/bin'};
    i = 1;
    while status && i<=length(paths)
        [status, result] = system(['ls ' paths{i} '/gprof*']);
        i = i + 1;
    end
    
    if status
        warning('m2c:profiling', ['Could not locate gprof in system directories.\n' ...
            'To process profiling data, please install gprof and add it to your path.']);
        found = false;
    else
        commands = strsplit(result);
        gprof = commands{1};
        found = true;
    end
end
end

function [gcov, found] = locate_gcov()
% Try to locate gcov in system directory
gcov = 'gcov';

[status, ~] = system('which gcov');
if status
    paths = {'/opt/local/bin', '/usr/local/bin', '/sw/bin'};
    i = 1;
    while status && i<=length(paths)
        [status, result] = system(['ls ' paths{i} '/gcov*']);
        i = i + 1;
    end
    
    if status
        warning('m2c:profiling', ['Could not locate gcov in system directories.\n' ...
            'To process profiling data, please install gcov and add it to your path.']);
        found = false;
    else
        commands = strsplit(result);
        gcov = commands{1};
        found = true;
    end
end
end

