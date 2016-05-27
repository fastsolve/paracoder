function [CC, CXX, found] = locate_gcc_mp
% Find gcc_mp

CC = 'gcc-mp';

[status, ~] = system(['which ' CC]);
if status
    paths = {'/opt/local/bin', '/usr/local/bin', '/sw/bin'};
    i = 1;
    while status && i<=length(paths)
        [status, result] = system(['ls ' paths{i} '/' CC '-*']);
        i = i + 1;
    end
    
    if status
        warning('m2c:buildEXE', ['Could not locate ' CC ' in system directories.\n' ...
            'Please install ' CC ' and add it to your path.']);
        CC = CC(1:3);
        found = false;
    else
        commands = strsplit(result);
        CC = commands{1};
        found = true;
    end
else
    found = true;
end

CXX = strrep(CC, 'gcc-mp', 'g++-mp');

end

