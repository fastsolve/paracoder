function [CC, CXX, found] = locate_pgcc
% Locates PGI compilers in path or in default system directory.

CC = 'pgcc';

[status, ~] = system(['which ' CC]);
if status
    if ismac
        paths = {'/opt/pgi/osx86-64'};
    else
        paths = {'/opt/pgi/linux86-64'};
    end
    
    i = 1;
    result = '';
    while isempty(result) && i<=length(paths)
        [~, result] = system(['find ' paths{i} ' -name pgcc']);
        i = i + 1;
    end
    
    if isempty(result)
        warning('m2c:locate_gpcc', ['Could not locate pgcc in system directories.\n' ...
            'Please install PGI compilers and add it to your path.']);
        CC = 'pgcc';
        found = false;
    else
        commands = strsplit(result);
        CC = commands{1};
        found = true;
    end
else
    found = true;
end

if ismac
    [~, macver] = system('sw_vers -productVersion');
    macver = strtrim(macver);
    ind = strfind(macver, '.');
    opts = [' -Wl,-macosx_version_min,' macver(1:ind(2)-1)];
else
    opts = '';
end

CXX = strrep(CC, 'pgcc', 'pgc++');
CC = [CC opts];
CXX = [CXX opts];

end
