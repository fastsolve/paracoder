function use = ckuse( mfile, func)
% Check whether an M-file calls a given function directly or indirectly.
%
%  use = ckuse( mfile, func)
%
%  It returns true if the M-file calls func. For efficiency, it only checks
%  user-level functions.

use = false;

if isempty(regexp(mfile, '[/\\]', 'once'))
    a2 = dir(which(mfile));
else
    a2 = dir(mfile);
end
if isempty(a2); error( 'File %s does not exist.', mfile); end

if ~exist('projroot', 'file') && ~exist('projroot', 'var')
    myprojroot = pwd;
    ind=regexp( pwd, '[\\|//]', 'start');
    if length(ind)>=3
        myprojroot = myprojroot(1:ind(3));
    end
else
    myprojroot = projroot;
end

funcpath=which(func);
if isempty(funcpath) || ~strncmp( funcpath, myprojroot, length(myprojroot))
    return;
end
[~,toks] = regexp( funcpath, ['(\w+)\.' mexext '$'], 'match', 'tokens');
if ~isempty(toks)
    % replace mex file by M file
    funcpath = which([toks{1}{1} '.p']);
    if isempty( funcpath)
        funcpath = which([toks{1}{1} '.m']);
    end
end

p = '';
if isempty(regexp(mfile, '[/\\]', 'once'))
    files = {which(mfile)};
else
    if mfile(1)=='/' || mfile(1)=='\' 
        files = {mfile};
    else
        ks = regexp(mfile, '[/\\]');
        p = path;
        addpath([pwd '/' mfile(1:ks(end))]); %#ok<MCAP>
        files = {[pwd '/' mfile]};
    end
end
start = 1;
n=1;

while true;
    for i=start:n
        if isequal(files{i}, funcpath)
            if ~isempty(p); path(p); end
            use = true; return;
        end
        if verLessThan('matlab', '8.3') 
            newdep = filter_files(depfun(files{i},'-quiet', '-toponly'), files, myprojroot);
        else
            newdep = filter_files(matlab.codetools.requiredFilesAndProducts(files{i}, 'toponly'), files, myprojroot);
        end
        files = [files; newdep]; %#ok<AGROW>
    end
    if n==length(files); break;
    else start=n+1; n=length(files); end
end
if ~isempty(p); path(p); end
end

function files = filter_files(files, tofilter, projroot)
% Remove files that are not under the project.
for i=length(files):-1:1
    if ~strncmp( files{i}, projroot, length(projroot))
        files(i) = [];
    else
        [~,toks] = regexp( files{i}, ['(\w+)\.' mexext '$'], 'match', 'tokens');
        if ~isempty(toks)
            % replace mex file by M file
            files{i} = which([toks{1}{1} '.p']);
            if isempty( files{i})
                files{i} = which([toks{1}{1} '.m']);
            end
            if ~strncmp( files{i}, projroot, length(projroot))
                files(i) = []; continue;
            end
        end
        
        for j=1:length(tofilter)
            if isequal( files(i), tofilter(j))
                files(i) = [];
                break;
            end
        end
    end
end
end
