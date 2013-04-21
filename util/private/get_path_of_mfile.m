function [mpath, func, mfile] = get_path_of_mfile( func)
%get_path_of_mfile Obtain the path of an M-file

if func(end-1)=='.'; func = func(1:end-2); end
if ispc
    k = regexp(func, '[/\\]');
else
    k = regexp(func, '/');
end
if ~isempty(k);
    mpath = func(1:k(end)); func = func(k(end)+1:end);
else
    mpath = '';
end

if ~isempty(mpath)
    if exist([mpath func '.p'], 'file');
        mfile = [mpath func '.p'];
    elseif exist( [mpath func '.m'], 'file');
        mfile = [mpath func '.m'];
    else
        error( 'm2c:FileNotFound', 'Could not locate function %s', func);
    end
elseif exist( ['./' func '.p'], 'file')
    mfile = [func '.p'];
elseif exist( ['./' func '.m'], 'file')
    mfile = [func '.m'];
else
    mfile = which ([func '.p']);
    if isempty(mfile); mfile = which ([func '.m']); end
    if isempty(mfile);
        error( 'm2c:FileNotFound', 'Could not locate file %s', mfile);
    end
    n = length(pwd);
    if strncmp( mfile, pwd, n); mfile = mfile(n+2:end); end
    k = regexp(mfile, '[/\\]');
    mpath = mfile(1:k(end));
end
