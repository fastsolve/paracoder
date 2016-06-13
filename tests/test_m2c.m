%Test M2C
testpath = fileparts(which('test_m2c.m'));

lines = grep_pattern([testpath '/*.m'], '%\!test');
files = regexp(lines, '[\.\/\\\w]+.m', 'match');

for j=1:length(files)
    file = files{j};
    fprintf(1, 'Testing file %s: ', file);
    mtest(file);
end
