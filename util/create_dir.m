function dir_name = create_dir(base, maxnum)
% Create a directory. If the directory exists, then attemps to
% append '_NNN' to the name.

dir_name = base;
[success,msg] = mkdir(dir_name);
if success && isempty(msg);
    return;
elseif ~strfind(msg,'exists')
    error('Could not create the directory. Got error message %s', msg);
end

if nargin<2; maxnum=1000; end
for counter=0:maxnum
    dir_name = sprintf('%s_%03d', base, counter);

    [success,msg] = mkdir(dir_name);    
    if success && isempty(msg);
        return;
    elseif ~strfind(msg,'exists')
        error('Could not create the directory. Got error message %s', msg);
    end
end

error('More than %d directories with name %s or %s_NNN.', maxnum, base, base);
