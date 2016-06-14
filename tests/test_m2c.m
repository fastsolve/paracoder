%Test M2C

m2croot = fileparts(which('startup_m2c.m'));
run([m2croot '/MOMP/startup.m']);
run([m2croot '/MCUDA/startup.m']);

testpath = fileparts(which('test_m2c.m'));

lines = grep_pattern([testpath '/*.m'], '%\!test');
files = regexp(lines, '[\.\/\\\w]+.m', 'match');

for j=1:length(files)
    file = files{j};
    fprintf(1, 'Testing file %s: ', file);
    mtest(file);
end