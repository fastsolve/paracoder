function writeFile(filename, str)
% Write a string into an ASCII file

fid = fopen(filename, 'wt');
if fid>=0
    fwrite(fid, uint8(str'));
    fclose(fid);
else
    error('Could not open file %s.', filename);
end
end
