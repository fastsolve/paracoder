function OK = ckdep(childfile, mfile, recursive)
% CKDEP   Check dependencies of a childfile compared with M-file and
%         its dependencies. If the MEX file exists for the mfile,
%         directory as the mfile is used, the MEX file will be temporarily
%         renamed during the checking and then removed back.
%
%  OK = ckdep(childfile, mfile)
%
%  OK = ckdep(childfile, mfile, recursive) checks recursively if any of
%  the dependencies are mex files. This is a slow process.
%
%  It returns true if childfile is newer than all its dependencies.

a1 = dir(childfile);
if isempty(a1); OK=false; return; end

if isempty(regexp(mfile, '[/\\]', 'once'))
    a2 = dir(which(mfile));
else
    a2 = dir(mfile);
end
if isempty(a2); error('File %s does not exist.', mfile); end

if exist('octave_config_info', 'builtin')
    % In octave, cannot check dependence
    OK=a1.datenum>=a2.datenum;
    return;
end

if exist([mfile(1:end-1) mexext], 'file')
    mexfiles = {mfile};
else
    mexfiles = {};
end

OK = true;
start = 1;
try
    while true
        for i=start:length(mexfiles)
            % Rename mex files
            movefile([mexfiles{i}(1:end-1) mexext], [mexfiles{i}(1:end-1) mexext '-ckdep']);
        end
        deps = matlab.codetools.requiredFilesAndProducts(mfile);
        
        [depfiles, newmexfiles] = split_files(deps);
        for j=1:length(depfiles)
            a2 = dir(depfiles{j});
            if a1.datenum<a2.datenum
                OK=false; break;
            end
        end
        
        if ~OK || nargin==2 || ~recursive || isempty(newmexfiles)
            break;
        else
            start = length(mexfiles)+1;
            mexfiles = [mexfiles newmexfiles]; %#ok<AGROW>
        end
    end
catch
end

try
    for i=1:length(mexfiles)
        % Move mex files back
        movefile([mexfiles{i}(1:end-1) mexext '-ckdep'], [mexfiles{i}(1:end-1) mexext]);
    end
catch
end


end

function [files, mexfiles] = split_files(files)
mexfiles = {};
% Remove files that are not under the project.
for i=length(files):-1:1
    if length(files{i})>length(mexext) && ...
            isequal(files{i}(end-length(mexext)+1:end), mexext)
        mfile = [files{i}(1:end-length(mexext)) 'm'];
        files(i) = [];
        mexfiles = [mexfiles mfile]; %#ok<AGROW>
    end
end
end
