function convert64(srcdir)
% Change int32_T to to int64_T in the input files
%     convert64(files...)

list = dir(srcdir);

for i=1:length(list)
    if length( list(i).name)>2 && ~strcmp( list(i).name, 'rtwtypes.h') && ...
            (strcmp( list(i).name(end-1:end), '.c') || ...
            strcmp( list(i).name(end-3:end), '.cpp') || strcmp( list(i).name(end-1:end), '.h'))
        convertfile( [srcdir '/' list(i).name]);
    end
end

function convertfile( file)
% Replace int32_T to int64_T in the file

fid = fopen(file, 'r+');
str = fread(fid, inf, '*char')';
str = regexprep( str, 'int32_T', 'int64_T');
str = regexprep( str, 'lib2mex_helper.c', 'lib2mex_helper64.c');
frewind( fid);
fwrite(fid, str, '*char');

fclose(fid);
