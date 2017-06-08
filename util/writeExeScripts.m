function writeExeScripts(funcname, mpath, cpath, m2c_opts)
% Generate scripts for building and running a standalone executable.

altapis = [funcname, strtrim(strrep(regexp(m2c_opts.codegenArgs, '(\w+)\s+-args', 'match'), ' -args', ''))];

if ~isequal(cpath, '.')
    outMfile = [cpath 'build_' funcname '_exe.m'];
end
clear(outMfile);

CFLAGS = ' -fPIC -std=c99 ';
CXXFLAGS = '-fPIC ';
LDFLAGS = '';

if m2c_opts.withPetsc
    CC = m2c_opts.petscCC{1};
    CXX = m2c_opts.petscCXX{1};
elseif m2c_opts.withMPI
    CC = m2c_opts.mpiCC{1};
    CXX = m2c_opts.mpiCXX{1};
elseif isempty(m2c_opts.cc)
    CC = 'gcc';
    CXX = 'g++';
    
    if ismac && m2c_opts.withOMP
        % Try to locate gcc-mp, with support of OpenMP
        [CC, CXX, found] = locate_gcc_mp;
        
        if ~found
            if m2c_opts.ompLibs
                warning('m2c:buildEXE', 'OpenMP is disabled.');
                m2c_opts.ompLibs = {};
            end
        end
    end
else
    CC = sprintf(' %s ', m2c_opts.cc{:});
end

if m2c_opts.optimLevel==0 || ~isempty(m2c_opts.ddd) || ~isempty(m2c_opts.gdb)
    CFLAGS = [CFLAGS ' -O0 -g'];
    CXXFLAGS = [CXXFLAGS ' -O0 -g'];
else
    CFLAGS = [CFLAGS '-O' num2str(m2c_opts.optimLevel) ' -g'];
    CXXFLAGS = [CXXFLAGS '-O' num2str(m2c_opts.optimLevel) ' -g'];
end

if m2c_opts.withOMP
    CFLAGS = [CFLAGS ' -fopenmp'];
    CXXFLAGS = [CXXFLAGS ' -fopenmp'];
    LDFLAGS = [LDFLAGS ' -fopenmp'];
end

if ~isempty(m2c_opts.gprof)
    CFLAGS = [CFLAGS ' -pg '];
    CXXFLAGS = [CXXFLAGS ' -pg '];
elseif ~isempty(m2c_opts.gcov)
    CFLAGS = [CFLAGS ' -fprofile-arcs -ftest-coverage '];
    CXXFLAGS = [CXXFLAGS ' -fprofile-arcs -ftest-coverage '];
    try delete([cpath '*.gcda']); catch; end
    try delete([cpath '*.gcno']); catch; end
end

if ~isempty(m2c_opts.cflags)
    % Overwrite CFLAGS
    CFLAGS = sprintf(' %s ', m2c_opts.cflags{:});
    CXXFLAGS = sprintf(' %s ', m2c_opts.cflags{:});
end
if ~isempty(m2c_opts.cppflags)
    CPPFLAGS = sprintf(' %s ', m2c_opts.cppflags{:});
else
    CPPFLAGS = '';
end
if ~isempty(m2c_opts.ldflags)
    LDFLAGS = [LDFLAGS sprintf(' %s ', m2c_opts.ldflags{:})];
end

if m2c_opts.withPetsc
    CFLAGS = [CFLAGS ' ' m2c_opts.petscCFLAGS{1} sprintf(' %s ', m2c_opts.petscInc{1})];
    CXXFLAGS = [CXXFLAGS ' ' m2c_opts.petscCXXFLAGS{1} sprintf(' %s ', m2c_opts.petscInc{1})];
end
if m2c_opts.withMKL
    CFLAGS = [CFLAGS sprintf(' %s ', m2c_opts.mklInc{1})];
    CXXFLAGS = [CXXFLAGS sprintf(' %s ', m2c_opts.mklInc{1})];
end
if m2c_opts.withCuda
    CFLAGS = [CFLAGS sprintf(' %s ', m2c_opts.cudaInc{1})];
    CXXFLAGS = [CXXFLAGS sprintf(' %s ', m2c_opts.cudaInc{1})];
end
if m2c_opts.withMPI
    CPPFLAGS = [CPPFLAGS sprintf(' %s ', m2c_opts.mpiInc{1})];
end

if m2c_opts.verbose
    CFLAGS = ['-v ' CFLAGS]; 
    CXXFLAGS = ['-v ' CXXFLAGS]; 
else
    CFLAGS = [CFLAGS ' -Wno-unused-function'];
    CXXFLAGS = [CXXFLAGS ' -Wno-unused-function'];
end

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

if m2c_opts.withNvcc
    cuda_out = [funcname '_cuda.o'];
    srcs = [funcname '.o ' cuda_out ' ' funcname '_mex.cpp ' funcname '_exe.cpp'];
else
    srcs = [funcname '.' m2c_opts.suf ' ' funcname '_mex.' m2c_opts.suf ' ' funcname '_exe.' m2c_opts.suf];
end

if exist([srcs ' ' funcname '_emxutil.' m2c_opts.suf], 'file')
    srcs = [srcs ' ' funcname '_emxutil.' m2c_opts.suf];
end

if m2c_opts.enableInf
    srcs = [srcs ' rtGetInf.' m2c_opts.suf  ' rtGetNaN.' m2c_opts.suf ' rt_nonfinite.' m2c_opts.suf];
end


% If m2c_opts.mexFile is nonempty, modify the output directory.
if ~isempty(m2c_opts.exeFile)
    if m2c_opts.exeFile{1}(1)=='/' || m2c_opts.exeFile{1}(1)=='\'
        exeFile = m2c_opts.exeFile{1};
    else
        exeFile = [repmat('../', 1, length(strfind(cpath(length(mpath)+1:end), '/'))) ...
            m2c_opts.exeFile{1}];
    end
    if exeFile(end) == '/' || exeFile(end) == '\'
        exeDir = exeFile;
        exeFile = [exeFile funcname '.exe'];
    else
        [exeDir, exeBase, ext] = fileparts(exeFile);
        exeFile = [exeDir '/' exeBase ext];
    end
else
    if isempty(mpath) || isequal(mpath, cpath(1:length(mpath)))
        exeFile = [repmat('../', 1, length(strfind(cpath(length(mpath)+1:end), '/'))) funcname '.exe'];
    elseif mpath(1)=='/' || mpath(1)=='\'
        exeFile = [mpath funcname '.exe'];
    else
        exeFile = [pwd '/' mpath funcname '.exe'];
    end
    exeDir = mpath;
end

[~, signature] = ckSignature(m2c_opts, 'exe');

filestr = sprintf('%s\n', ...
    ['% Build script for ' funcname], signature, '', ...
    ['if exist(''isnewer'', ''file'') && ~isnewer(''' exeFile ''', ''build_' ...
    funcname '_exe.m'', ''' funcname '_exe.' m2c_opts.suf ''')']);
if ~m2c_opts.quiet
    filestr = sprintf('%s\n%s', filestr, ...
        '    fprintf(''Entering %s\n'', pwd);');
end

if m2c_opts.withNvcc
    NVCC = [m2c_opts.cudaDir{1} '/bin/nvcc'];
    
    NVCC_CXXFLAGS = [regexprep(CXXFLAGS, '(-[^\s]+)', '-Xcompiler $1'), ' -m64 -arch=sm_20 '];
    cuda_out = [funcname '_cuda.o'];
    nvccCmd1 = [NVCC ' ' CPPFLAGS ' '  NVCC_CXXFLAGS ' -dc ' funcname '.cu -o ' funcname '.o'];
    nvccCmd2 = [NVCC ' ' NVCC_CXXFLAGS ' -dlink ' funcname '.o  -o ' cuda_out];
    
    filestr = sprintf('%s\n', filestr, ...
        ['    nvccCmd1 = [''' nvccCmd1 '''];'], ...
        ['    nvccCmd2 = ''' nvccCmd2 ''';']);
    
    if ~m2c_opts.quiet
        filestr = sprintf('%s\n', filestr, ...
            '    disp(nvccCmd1); [status,cmdout] = system(nvccCmd1);', ...
            '    if status; error(cmdout); else fprintf(cmdout); end', ...
            '    disp(nvccCmd2); [status,cmdout] = system(nvccCmd2);', ...
            '    if status; error(cmdout); else fprintf(cmdout); end');
    else
        filestr = sprintf('%s\n', ...
            '    [status,cmdout] = system(nvccCmd1); if status error(cmdout); end', ...
            '    [status,cmdout] = system(nvccCmd2); if status error(cmdout); end');
    end
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
    '    end');

if m2c_opts.withNvcc
    filestr = sprintf('%s\n', filestr, ...
        ['    build_cmd = [''' CXX ' ' CPPFLAGS CXXFLAGS ' -DBUILD_MAT -I"'' incdir ''" '...
        srcs ' -o ' exeFile ' ' LDFLAGS ' ' libs '''  matlibs];']);
else
    filestr = sprintf('%s\n', filestr, ...
        ['    build_cmd = [''' CC ' ' CPPFLAGS CFLAGS ' -DBUILD_MAT -I"'' incdir ''" '...
        srcs ' -o ' exeFile  ' ' LDFLAGS  ' ' libs '''  matlibs];']);
end

if ~m2c_opts.quiet
    filestr = sprintf('%s\n', filestr, ...
        '    disp(build_cmd);', ...
        '    [status,cmdout] = system(build_cmd);', ...
        '    if status; error(cmdout); else fprintf(cmdout); end', ...
        'else', ...
        ['    fprintf(''' funcname '.exe is up to date.\n'');'], ...
        'end');
else
    filestr = sprintf('%s\n', filestr, ...
        '    [status,cmdout] = system(build_cmd); if status error(cmdout); end', ...
        'end');
end

% Nested function for writing out mex script
writeFile(outMfile, filestr);

% Write M-file wrapper function for calling EXE within MATLAB
writeExeMWrapper(altapis, cpath, exeDir, funcname, m2c_opts, CC);

end

function writeExeMWrapper(altapis, cpath, exeDir, funcname, m2c_opts, CC)
% Generate M-file for reading and writing output through MAT files.

if exeDir(1) == '/' || exeDir(1) == '\'
    outfile = [exeDir 'run_' funcname '_exe.m'];
else
    outfile = [cpath exeDir 'run_' funcname '_exe.m'];
end

% Backup file
if (exist(outfile, 'file'))
    copyfile(outfile, [outfile '.bak']);
end

filestr = sprintf('%s\n', ...
    ['function varargout = run_' funcname '_exe(varargin)'], ...
    '% Invoke EXE file by passing variables through MAT files.', '',...
    'tmpdir = getenv(''TMPDIR'');', ...
    'if isempty(tmpdir); tmpdir = ''/tmp/''; elseif (tmpdir(end)~=''/''); tmpdir = [tmpdir ''/'']; end', '', ...
    'suf = [''_'' num2str(feature(''getpid'')) ''.mat''];', ...
    ['infile = [tmpdir ''' funcname '_in'' suf];'], ...
    ['outfile = [tmpdir ''' funcname '_out'' suf];'], '', ...
    ['mdir = fileparts(which(''run_' funcname '_exe.m''));'], ...
    'if isequal(mdir, pwd); mdir = ''./''; else mdir = [mdir ''/'']; end', '', ...
    '% Delete MAT files', ...
    'if exist(infile, ''file''); delete(infile); end', ...
    'if exist(outfile, ''file''); delete(outfile); end', ...
    '% Export input arguments into MAT file', ...
    'm = struct();', '', ...
    'for i=1:nargin', ...
    '    try', ...
    '        m.([''input_'' int2str(i)]) = varargin{i};', ...
    '    catch', ...
    '        error([''Failed to write out input variable '' int2str(i)]);', ...
    '    end', ...
    'end', ...
    'save(infile, ''-struct'', ''m'', ''-v7'');');

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
            breakponts = sprintf(' -ex "break __%s_api" ', altapis{:});
            
            cmdpre = [ddd ' --debugger ''''' gdb breakponts ' -ex run -ex where'''' --args '];
        end
        echo = '';
    end
elseif ~isempty(m2c_opts.gdb)
    gdb = strtrim(sprintf(' %s ', m2c_opts.gdb{:}));
    if isempty(gdb)
        % Find gdb
        gdb = locate_gdb();
        
        if ~isempty(gdb)
            % Add breakpoints
            breakponts = sprintf(' -ex "break __%s_api" ', altapis{:});
            if ismac
                gdb = ['sudo ' gdb];
            end
            cmdpre = ['xterm -e ' gdb breakponts ' -ex run -ex where --args '];
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
        ['[status,result] = system(cmd' echo ');'], ...
        'if status', ...
        '    error(''%s'', result);', ...
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
    'm = load(outfile);', '', ...
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

    if cpath(1)~='/' && cpath(1)~='\'
        cpath = [pwd '/' cpath]; % User absolute path
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

