function writeMexScript(funcname, cpath, m2c_opts)
% Generate a script for building the Mex file.

% Nested function for writing out mex script
if ~isequal(cpath, '.')
    outMfile = [cpath '/mex_' funcname '.m'];
end
clear(outMfile);

fid = fopen(outMfile, 'w');
if (fid<0); error('m2c:OpenOutputFile', msg); end

mexflags = '';

if isempty(m2c_opts.cc) && ismac && ~isempty(m2c_opts.ompLibs)
    % Try to locate gcc-mp, with support of OpenMP
    [CC, found] = locate_gcc_mp(m2c_opts.useCpp);
    if ~found
        if ~isempty(m2c_opts.ompLibs)
            warning('m2c:buildEXE', 'OpenMP is disabled.');
            m2c_opts.ompLibs = {};
        end
        mexflags = [mexflags ' CC=''''' CC ''''''];
    end
elseif ~isempty(m2c_opts.cc)
    CC = sprintf('%s ', m2c_opts.cc{:});
    mexflags = [mexflags ' CC=''''' CC ''''''];
end

switch m2c_opts.optLevel
    case '0'
        cflags = ['-O' m2c_opts.optLevel];
    case {'1','2','3'}
        cflags = ['-O' m2c_opts.optLevel ' -DNDEBUG'];
    otherwise
        cflags = '';
end

if ~isempty(m2c_opts.cflags)
    % Overwrite cflags
    cflags = sprintf(' %s ', m2c_opts.cflags{:});
end

mexflags = [mexflags ' COPTIMFLAGS=''''' cflags ''''''];
if m2c_opts.debugInfo; 
    mexflags = [mexflags ' CDEBUGFLAGS=''''-g'''''];
end

if ~isempty(m2c_opts.mexflags)
    % Overwrite mexflags
    mexflags = sprintf(' %s ', mexflags.mexflags{:});
end
if m2c_opts.verbose; mexflags = [mexflags ' -v']; end

libs = sprintf(' %s ', m2c_opts.libs{:});
libs = [libs sprintf(' %s ', m2c_opts.lapackLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.mpiLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.ompLibs{:})];
libs = [libs sprintf(' %s ', m2c_opts.accLibs{:})];

srcs = [funcname '.' m2c_opts.suf ' ' funcname '_mex.' m2c_opts.suf];
if m2c_opts.enableInf
    srcs = [srcs ' rtGetInf.' m2c_opts.suf  ' rtGetNaN.' m2c_opts.suf ' rt_nonfinite.' m2c_opts.suf];
end

% Place mex file in the same directory as the M file.
mexdir = '../../../';

[~, signature] = ckCompOpt(m2c_opts, 'mex');

% Place mex file in the same directory as the M file.
fprintf(fid, '%s\n', ...
    ['% Build script for ' funcname], signature, '', ...
    ['if ~isnewer([''' mexdir funcname '.'' mexext], ''mex_' funcname '.m'', ''' funcname '_mex.' m2c_opts.suf ''')'], ...
    '    dir = which(''opaque_obj.m''); dir=dir(1:end-12);', '');

fprintf(fid, '%s\n', ...
    '    if exist(''octave_config_info'', ''builtin''); output = ''-DMATLAB_MEX_FILE -o''; else output = ''-largeArrayDims -output''; end', ...
    ['    build_cmd = [''mex ' mexflags ' -I"'' dir ''include" '...
    srcs ' '' output '' ' mexdir funcname  libs '''];'], ...
    '    fprintf(''Entering %s\n'', pwd);', ...
    '    disp(build_cmd);', ...
    '    eval(build_cmd);', ...
    'else', ['    fprintf(''' funcname '.%s is up to date.\n'', mexext);'], 'end');


fclose(fid);
end