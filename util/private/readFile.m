function str = readFile(filename)
% Read an ASCII file into a string

fid = fopen(filename, 'rt');
if fid>=0
    str = fread(fid,inf,'*char')';
    fclose(fid);
else
    warning('m2c:CannotOpenFile', 'Could not open file %s\n', filename);
    str = '';
end
end
