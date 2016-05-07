function writeMexScript(funcname, cpath, m2c_opts)
% Generate a script for building the Mex file.

switch m2c_opts.optLevel
    case {'0', 'g'}
        opflags = ['-O' m2c_opts.optLevel];
    case {'1','2','3'}
        opflags = ['-O' m2c_opts.optLevel ' -DNDEBUG'];
    otherwise
        opflags = '';
end

% Nested function for writing out mex script
if ~isequal(cpath, '.')
    outMfile = [cpath '/mex_' funcname '.m'];
end
clear(outMfile);

fid = fopen(outMfile, 'w');
if (fid<0); error('m2c:OpenOutputFile', msg); end

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
    funcname '.' m2c_opts.suf ' ' funcname '_mex.' m2c_opts.suf ' '' output '' ' mexdir funcname ' '' ' mpildflag ompldflag libs '];'], ...
    '    fprintf(''Entering %s\n'', pwd);', ...
    '    disp(cmd);', ...
    '    eval(cmd);', ...
    'else', ['    fprintf(''' funcname '.%s is up to date.\n'', mexext);'], 'end');


fclose(fid);
end