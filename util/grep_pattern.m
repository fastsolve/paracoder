function lines = grep_pattern(filepat, pattern)
%GREP_PATTERN    file pattern searcher
%     lines = grep_pattern(filepat, pattern)
%
%It emulates the grep command in UNIX 
%     > grep "pattern" filepat
%
%The output format is "filename:matchedline" for each file. 
%It reports only the first match for each file.
%It works on both UNIX and Windows systems.

lines = '';
files = dir(filepat);

% Determine the path
if ispc
    k = regexp(filepat, '[/\\]');
else
    k = regexp(filepat, '/');
end
if ~isempty(k)
    fpath = filepat(1:k(end));
else
    fpath = '';
end

for i=1:length(files)
    file = files(i).name;
    
    fid = fopen([fpath file], 'rt');
    if fid>=0
        str = fread(fid,'*char')';
        fclose(fid);
    else
        continue;
    end

    line = regexp(str, ['[^\n]*' pattern '[^\n]*\n'], 'once', 'match');
    
    if ~isempty(line)
        lines = sprintf('%s%s%s:%s', lines, fpath, file, line);
    end
end
