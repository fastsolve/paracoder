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
elseif isempty(m2c_opts.cc)
    if m2c_opts.useCpp
        CC = 'g++';
    else
        CC = 'gcc';
    end

    if ismac && m2c_opts.withOMP
        % Try to locate gcc-mp, with support of OpenMP
        [CC, found] = locate_gcc_mp(m2c_opts.useCpp);
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

switch m2c_opts.optLevel
    case '0',
        cflags = ['-O' m2c_opts.optLevel ' -DM2C_DEBUG=1 -g -Wall -Wno-unused-function'];
    case {'1','2','3'}
        cflags = ['-O' m2c_opts.optLevel ' -DNDEBUG -DM2C_DEBUG=0 -g -Wall -Wno-unused-function'];
    otherwise
        cflags = '-g -Wall -Wunused-function';
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
if m2c_opts.withPetsc
    % Append petscInc to cflags
    cflags = [cflags sprintf(' %s ', m2c_opts.petscInc{1})];
end

if m2c_opts.verbose; cflags = ['-v ' cflags]; end

libs = sprintf(' %s ', m2c_opts.libs{:});
libs = [libs sprintf(' %s ', m2c_opts.efenceLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.lapackLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.mpiLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.ompLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.accLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.petscLibs{:})];

% Place exe file in the same directory as the M file.
exedir = '../../../';

[~, signature] = ckSignature(m2c_opts, 'exe');

filestr = sprintf('%s\n', ...
    ['% Build script for ' funcname], signature, '', ...
    ['if ~isnewer(''' exedir funcname '.exe'', ''build_' funcname '_exe.m'', ''' funcname '_exe.' m2c_opts.suf ''')'], ...
    '    m2cdir = which(''opaque_obj.m''); m2cdir=m2cdir(1:end-12);', '');

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
    ['    build_cmd = [''' CC ' ' cflags ' -DBUILD_MAT -I"'' incdir ''" -I"'' m2cdir ''include" '...
    srcs ' -o ' exedir funcname '.exe '  libs '''  matlibs];'], ...
    '    fprintf(''Entering %s\n'', pwd);', ...
    '    disp(build_cmd);', ...
    '    system(build_cmd, ''-echo'');', ...
    'else', ['    fprintf(''' funcname '.exe is up to date.\n'');'], 'end');

% Nested function for writing out mex script
writeFile(outMfile, filestr);

% Write M-file wrapper function for calling EXE within MATLAB
writeExeMWrapper(altapis, cpath, funcname, m2c_opts, CC);

end

function writeExeMWrapper(altapis, cpath, funcname, m2c_opts, CC)
% Generate M-file for reading and writing output through MAT files.

outfile = ['run_' funcname '_exe.m'];
build_cmd = ['build_' funcname '_exe.m'];

% Backup file
if (exist(outfile, 'file'))
    copyfile(outfile, [outfile '.bak']);
end

filestr = sprintf('%s\n', ...
    ['function varargout = run_' funcname '_exe(varargin)'], ...
    '% Invoke EXE file by passing variables through MAT files.', '',...
    '% Build the executable if needed', ...
    ['run(''codegen/lib/' funcname '/' build_cmd ''');'], '', ...
    '% Delete MAT files', ...
    ['if exist(''' funcname '_in.mat'', ''file''); delete(''' funcname '_in.mat''); end'], ...
    ['if exist(''' funcname '_out.mat'', ''file''); delete(''' funcname '_out.mat''); end'], ...
    '% Export input arguments into MAT file', ...
    ['m = matfile(''' funcname '_in.mat'', ''Writable'', true);'], '', ...
    'for i=1:nargin', ...
    '    m.([''input_'' int2str(i)]) = varargin{i};', ...
    'end', '');

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

filestr = sprintf('%s\n', filestr, ...
    '% Call executable using the system command', ...
    ['cmd = [''' cmdpre './' funcname '.exe '' ...'], ...
    ['       int2str(nargin) '' ' funcname '_in.mat '' ...'], ...
    ['       int2str(nargout) '' ' funcname '_out.mat''];']);

if isempty(cmdpre)
    filestr = sprintf('%s\n', filestr, ...
        ['[status,~] = system(cmd' echo ');'], ...
        'if status', ...
        ['    error(''' funcname '.exe failed'');'], ...
        'end');
else
    filestr = sprintf('%s\n', filestr, 'disp(cmd);', ...
        ['[~,~] = system(cmd' echo ');']);
end

filestr = sprintf('%s\n', filestr, ...
    '% Import output arguments from MAT file', ...
    'varargout = cell(1, nargout);', ...
    ['m = matfile(''' funcname '_out.mat'', ''Writable'', false);'], '', ...
    'for i=1:nargout', ...
    '    try', ...
    '        varargout{i} = m.([''output_'' int2str(i)]);', ...
    '    catch', ...
    '        error([''Could not assign output variable '' int2str(i)]);', ...
    '    end', ...
    'end', '', ...
    '% Delete MAT files', ...
    ['if exist(''' funcname '_in.mat'', ''file''); delete(''' funcname '_in.mat''); end'], ...
    ['if exist(''' funcname '_out.mat'', ''file''); delete(''' funcname '_out.mat''); end'] ...
    );

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

