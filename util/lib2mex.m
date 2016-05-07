function lib2mex(funcname, mpath, cpath, m2c_opts)
% Generate a MEXFunction and main function for a C library created by m2c.
% It also generates MATLAB scripts for building the generated files.
% Before calling this script, m2c should have been called on the function,
% or codegen should be present. The generated C file and build script
% are located in codegen/lib/funcname.
%
% See also m2c

if nargin<1
    error('too few input arguments');
end

switch m2c_opts.optLevel
    case {'0', 'g'}
        opflags = ['-O' m2c_opts.optLevel];
    case {'1','2','3'}
        opflags = ['-O' m2c_opts.optLevel ' -DNDEBUG'];
    otherwise
        opflags = '';
end

altapis = [funcname, strtrim(strrep(regexp(m2c_opts.codegenArgs, '(\w+)\s+-args', 'match'), ' -args', ''))];

% Write out C file.
outdir = [mpath 'codegen/lib/' funcname];

if m2c_opts.genExe && ...
        ~ckCompOpt('mex', [cpath  '/' func '_mex.c'], m2c_opts)
    % Write out a build script for MEX
    writeMexScript(['mex_' funcname '.m'], opts);
end

if m2c_opts.genExe && ...
        ~ckCompOpt('exe', [cpath  '/' func '_mex.c'], m2c_opts)
    % Write out a build script for EXE
    m2c_opts = writeExeScript(['build_' funcname '_exe.m'], opts, m2c_opts);
    
    % Write M-file wrapper function for calling EXE within MATLAB
    writeExeMWrapper(altapis, outdir, funcname, m2c_opts);
end

    function writeMexScript(outMfile, opts)
        % Nested function for writing out mex script
        if ~isequal(outdir, '.')
            outMfile = [outdir '/' outMfile];
        end
        clear(outMfile);
        
        % Nested function for writing out mex script
        fid = fopen(outMfile, 'w');
        if (fid<0); error('lib2mex:OpenOutputFile', msg); end
        
        if m2c_opts.enableMpi
            mpiopts = '    [mpicflag, mpildflag] = mpiflags;';
            mpicflag = ' '' '' mpicflag ';
            mpildflag = ' '' '' mpildflag ';
        else
            mpiopts = '';
            mpicflag = ''; mpildflag = '';
        end
        
        if m2c_opts.enableOmp
            ompopts = '    [ompcflag, ompldflag] = ompflags;';
            ompcflag = ' '' '' ompcflag';
            ompldflag = ' '' '' ompldflag ';
        else
            ompopts = '';
            ompcflag = ''; ompldflag = '';
        end

        if m2c_opts.enableAcc
            assert(false); % Not yet implemented
        end
 
        if m2c_opts.useLapack
            libs = ' -lmwlapack -lmwblas ';
        else
            libs = '';
        end

        % Place mex file in the same directory as the M file.
        mexdir = '../../../';
        
        % Place mex file in the same directory as the M file.
        fprintf(fid, '%s\n', ...
            ['% Build script for ' funcname], ...
            ['if ~isnewer([''' mexdir funcname '.'' mexext], ''' funcname '_mex.' m2c_opts.suf ''', ''' funcname '.' m2c_opts.suf ''')'], ...
            '    dir = which(''opaque_obj.m''); dir=dir(1:end-12);', '');
        
        if mpiopts; fprintf(fid, '%s\n', mpiopts); end
        if ompopts; fprintf(fid, '%s\n', ompopts); end
        
        ldflags = '';
        if m2c_opts.verbose; ldflags = '-v '; end
        if m2c_opts.debugInfo; ldflags = [ldflags ' -g ']; end

        fprintf(fid, '%s\n', ...
            '    if exist(''octave_config_info'', ''builtin''); output = ''-DMATLAB_MEX_FILE -o''; else output = ''-largeArrayDims -output''; end', ...
            ['    cmd = [''mex ' ldflags ' COPTIMFLAGS=''''' opflags '''''''' mpicflag ompcflag ' '' -I"'' dir ''include" '...
            funcname '.' m2c_opts.suf ' ' funcname '_mex.' m2c_opts.suf ' '' output '' ' mexdir funcname ' '' '  opts mpildflag ompldflag libs '];'], ...
            '    fprintf(''Entering %s\n'', pwd);', ...
            '    disp(cmd);', ...
            '    eval(cmd);', ...
            'else', ['    fprintf(''' funcname '.%s is up to date.\n'', mexext);'], 'end');
        
        
        fclose(fid);
    end

    function m2c_opts = writeExeScript(outMfile, opts, m2c_opts)        
        if ~isequal(outdir, '.')
            outMfile = [outdir '/' outMfile];
        end
        clear(outMfile);
                
        % Nested function for writing out mex script
        fid = fopen(outMfile, 'w');
        if (fid<0); error('lib2mex:OpenOutputFile', msg); end
        
        if m2c_opts.efence
            libs = locate_efence();
        else
            libs = '';
        end
        
        if m2c_opts.useLapack
            libs = [''' ' libs ' -lmwlapack -lmwblas '''];
        elseif libs
            libs = [''' ' libs ' '''];
        end
        
        ldflags = '-g ';
        if m2c_opts.verbose; ldflags = '-g -v '; end
        
        if ismac
            % Try to locate gcc-mp, with support of OpenMP
            [CC, found] = locate_gcc_mp();
            if ~found
                if m2c_opts.enableOmp 
                    warning('m2c:lib2mex', 'OpenMP is disabled.');
                    m2c_opts.enableOmp = false;
                end
                CC = 'cc';
            else
                m2c_opts.CC = CC;
            end
        else
            CC = 'gcc';
        end
        
        if m2c_opts.enableMpi
            mpiopts = '    [mpicflag, mpildflag] = mpiflags;';
            mpicflag = ' '' '' mpicflag ';
            mpildflag = ' '' '' mpildflag ';
        else
            mpiopts = '';
            mpicflag = ''; mpildflag = '';
        end
        
        if m2c_opts.enableOmp
            ompopts = '    [ompcflag, ompldflag] = ompflags;';
            ompcflag = ' '' '' ompcflag';
            ompldflag = ' '' '' ompldflag ';
        else
            ompopts = '';
            ompcflag = ''; ompldflag = '';
        end

        if m2c_opts.enableAcc
            assert(false); % Not yet implemented
        end

        if m2c_opts.gprof
            ldflags = [ldflags ' -pg '];
        elseif m2c_opts.gcov
            ldflags = [ldflags ' -fprofile-arcs -ftest-coverage -fPIC '];
            try delete([outdir '/*.gcda']); catch; end
            try delete([outdir '/*.gcno']); catch; end
        end
        
        % Place exe file in the same directory as the M file.
        exedir = '../../../';
                
        fprintf(fid, '%s\n', ...
            ['% Build script for ' funcname ' on ' computer], ...
            ['if ~isnewer(''' exedir funcname '.exe'', ''' funcname '_exe.' m2c_opts.suf ''', ''' funcname '.' m2c_opts.suf ''')'], ...
            '    m2cdir = which(''opaque_obj.m''); m2cdir=m2cdir(1:end-12);', '');

        if mpiopts; fprintf(fid, '%s\n', mpiopts); end
        if ompopts; fprintf(fid, '%s\n', ompopts); end

       
        fprintf(fid, '%s\n', ...
            '    incdir = [matlabroot ''/extern/include''];', ...
            '    bindir = [matlabroot ''/bin/'' lower(computer)];', ...
            '    if isequal(computer, ''MACI64'')', ...
            '        matlibs = [''-L'' bindir '' -Wl,-rpath -Wl,'' bindir '' -lmat -lmx -lm''];', ...
            '    elseif isequal(computer, ''GLNXA64'')', ...
            '        matlibs = [''-L'' bindir '' -Wl,-rpath='' bindir '' -lmat -lmx -lm''];', ...
            '    else', ...
            '        error(''Building executable is not supported on %s\n'', computer);', ...
            '    end', ...
            ['    cmd = [''' CC ' ' ldflags '' '' opflags mpicflag ompcflag ' -DBUILD_MAT -I"'' incdir ''" -I"'' m2cdir ''include" '...
             funcname '.' m2c_opts.suf ' ' funcname '_mex.' m2c_opts.suf ' ' funcname '_exe.' m2c_opts.suf ' -o ' ...
             exedir funcname '.exe '' '  opts libs mpildflag ompldflag ' matlibs];'], ...
            '    fprintf(''Entering %s\n'', pwd);', ...
            '    disp(cmd);', ...
            '    system(cmd, ''-echo'');', ...
            'else', ['    fprintf(''' funcname '.exe is up to date.\n'');'], 'end');
        
        fclose(fid);
    end
end

function writeExeMWrapper(altapis, srcdir, funcname, m2c_opts)
% Generate M-file for reading and writing output through MAT files.

outfile = ['run_' funcname '_exe.m'];
build_cmd = ['build_' funcname '_exe.m'];

% Backup file
if (exist(outfile, 'file'))
    copyfile(outfile, [outfile '.bak']);
end
fid = fopen(outfile, 'w');

fprintf(fid, '%s\n', ...
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

if m2c_opts.ddd
    % Find ddd
    ddd = locate_ddd();

    % Find gdb
    gdb = locate_gdb();
    
    if ~isempty(gdb) && ~isempty(ddd) 
        % Add breakpoints
        breakponts = sprintf(' -ex "break %s"', altapis{:});
        
        cmdpre = [ddd ' --debugger ''''' gdb breakponts ' -ex run -ex where'''' --args '];
    end
    echo = '';
elseif m2c_opts.valgrind
    valgrind = locate_valgrind();
    % See http://valgrind.org/docs/manual/manual-core.html for documentation
    % Other useful options include --partial-loads-ok=yes --track-origins=yes
    cmdpre = [valgrind ' --leak-check=summary --show-possibly-lost=no --gen-suppressions-all ' ...
        '--suppressions=' fileparts(which('m2c.m')) '/' 'valgrind.supp '];
    echo = ', ''-echo''';
end

fprintf(fid, '%s\n', ...
    '% Call executable using the system command', ...
    ['cmd = [''' cmdpre './' funcname '.exe '' ...'], ...
    ['       int2str(nargin) '' ' funcname '_in.mat '' ...'], ...
    ['       int2str(nargout) '' ' funcname '_out.mat''];']);

if isempty(cmdpre)
    fprintf(fid, '%s\n', ...
        ['[status,~] = system(cmd' echo ');'], ...
        'if status', ...
        ['    error(''' funcname '.exe failed'');'], ...
        'end');
else
    fprintf(fid, '%s\n', 'disp(cmd);', ...
        ['[~,~] = system(cmd' echo ');']);
end

fprintf(fid, '%s\n', '', ...
    '% Import output arguments from MAT file', ...
    'varargout = cell(1, nargout);', ...
    ['m = matfile(''' funcname '_out.mat'', ''Writable'', false);'], '', ...
    'for i=1:nargout', ...
    '    try', ...
    '        varargout{i} = m.([''output_'' int2str(i)]);', ...
    '    catch', ...
    '        warning([''Could not assign output variable '' int2str(i)]);', ...
    '        break;', ...
    '    end', ...
    'end', '', ...
    '% Delete MAT files', ...
    ['if exist(''' funcname '_in.mat'', ''file''); delete(''' funcname '_in.mat''); end'], ...
    ['if exist(''' funcname '_out.mat'', ''file''); delete(''' funcname '_out.mat''); end'] ...
    );

if m2c_opts.gprof
    % Find command for gprof
    gprof = locate_gprof();

    fprintf(fid, '%s\n', '', ...
        '% Process gprof results', ...
        'if exist(''gmon.out'', ''file'')', ...
        ['    [~, result] = system(''' gprof ' --brief --flat-profile=' funcname '.c ' funcname '.exe gmon.out'');'], ...
        '    cells = strsplit(result, ''\n'');', ...
        '    fprintf(''            Function Flat Profile (top 10):\n'');', ...
        '    fprintf(''%s\n'', cells{3:min(length(cells),14)});', ...
        ['    [~, result] = system(''' gprof ' -l --brief --flat-profile=' funcname '.c ' funcname '.exe gmon.out'');'], ...
        '    cells = strsplit(result, ''\n'');', ...
        '    fprintf(''            Line-by-Line Flat Profile (top 30):\n'');', ...
        '    fprintf(''%s\n'', cells{3:min(length(cells),34)});', ...
        'else', ...
        '    fprintf(''Did not find valid profiling file gmon.out.\n'');', ...
        'end');
end

if m2c_opts.gcov
    % Find command for gcov
    if isfield(m2c_opts, 'CC')
        % Use gcov matching the version of gcc
        gcov = strrep(m2c_opts.CC, 'gcc', 'gcov');
    else
        gcov = locate_gcov();
    end

    fprintf(fid, '%s\n', '', ...
        '% Process code coverage results', ...
        ['if exist(''' srcdir '/' funcname '.gcda'', ''file'')'], ...
        ['    system('' cd ' srcdir '; ' gcov ' -b -c ' funcname '.c'');'], ...
        ['    fprintf(''Openning up code coverage ' srcdir '/' funcname '.c.gcov for ' funcname 'in editor.\n'');'], ...
        ['    edit(''' srcdir '/' funcname '.c.gcov'');'], ...
        'else', ...
        ['    fprintf(''Did not find valid profiling file ' srcdir '/' funcname '.gcda.\n'');'], ...
        'end');
end

fprintf(fid, 'end\n');
fclose(fid);

end

function [libs, found] = locate_efence
% Find efence
libs = '-lefence';

if ~exist('/usr/lib/libefence.a', 'file')
    status = -1;
    
    files = {'/usr/local/lib/libefence.a', ...
        '/opt/local/lib/libefence.a', '/sw/lib/libefence.a'};
    i = 1;
    while status && i<=length(files)
        status = ~exist(files{i}, 'file');
        i = i + 1;
    end
    
    if status
        warning('m2c:lib2mex', ['Could not locate libefence.a in system directories.\n' ...
            'Please install efence.']);
        libs = '';
        found = false;
    else
        libs = ['-L' fileparts(files{i}) ' -lefence'];
        found = true;
    end
end
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
        warning('m2c:lib2mex', ['Could not locate valgrind in system directories.\n' ...
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
        warning('m2c:lib2mex', [result(1:end-1) ' may fail on Mac OS X 10.11 El Capitan.\n', ...
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
        warning('m2c:lib2mex', ['Could not locate ddd in system directories.\n' ...
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
        warning('m2c:lib2mex', ['Could not locate gdb in system directories.\n' ...
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
    warning('m2c:lib2mex', 'gprof may not work on Mac.\n');
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

function [CC, found] = locate_gcc_mp
% Find gcc_mp
CC = 'gcc-mp';

[status, ~] = system('which gcc-mp');
if status
    paths = {'/opt/local/bin', '/usr/local/bin', '/sw/bin'};
    i = 1;
    while status && i<=length(paths)
        [status, result] = system(['ls ' paths{i} '/gcc-mp-*']);
        i = i + 1;
    end
    
    if status
        warning('m2c:lib2mex', ['Could not locate gcc-mp in system directories.\n' ...
            'Please install gcc-mp and add it to your path.']);
        CC = 'cc';
        found = false;
    else
        commands = strsplit(result);
        CC = commands{1};
        found = true;
    end
end
end
