%Test MMPI

if exist('./test_mmpi.m', 'file')
    lines = [grep_pattern('../mpi/mpi_*.m', '%\!test') ...
        grep_pattern('../*.m', '%\!test')];
else
    lines = [grep_pattern('./mpi/mpi_*.m', '%\!test') ...
        grep_pattern('./*.m', '%\!test')];
end


files = regexp(lines, '[\.\/\\\w]+.m', 'match');

for j=1:length(files)
    file = files{j};
    fprintf(1, 'Testing file %s: ', file);
    mtest(file);
end
