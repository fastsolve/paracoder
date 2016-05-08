function [mpath, func, mfile] = get_path_of_mfile(mfile)
%get_path_of_mfile Obtain the path of an M-file

[mpath, func, ~] = fileparts(mfile);

if ~isempty(mpath)
    mpath = [mpath '/'];
    if exist([mpath func '.p'], 'file');
        mfile = [mpath func '.p'];
    elseif exist([mpath func '.m'], 'file');
        mfile = [mpath func '.m'];
    else
        error('m2c:FileNotFound', 'Could not locate function %s', func);
    end
elseif exist(['./' func '.p'], 'file')
    mfile = [func '.p'];
elseif exist(['./' func '.m'], 'file')
    mfile = [func '.m'];
else
    mfile = which ([func '.p']);
    if isempty(mfile); mfile = which ([func '.m']); end
    
    if isempty(mfile);
        error('m2c:FileNotFound', 'Could not locate file %s', mfile);
    end
    mpath = [fileparts(mfile) '/'];
end
