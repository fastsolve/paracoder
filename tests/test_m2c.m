function test_m2c
% test script for paracoder

if isoctave
    test_hdl = @test;
else
    test_hdl = @mtest;
end

% Test vectors, matrices, and KSP solvers
lines = [grep_pattern([m2croot '/api/crs/crs_*.m'], '%\!test')];

files = regexp(lines, '[\.\/\\\w]+.m', 'match');

for j=1:length(files)
    file = files{j};
    fprintf(1, 'Testing file %s:\n', file(length(m2croot)+2:end));
    [n, nmax] = test_hdl(file);
    if n<nmax
        error('FAILED %d out of %d tests\n', nmax-n, nmax)
    else
        fprintf(1, 'PASSED %d out of %d tests\n', n, nmax);
    end
end

end


% %Test M2C
% 
% testpath = fileparts(which('test_m2c.m'));
% 
% lines = [grep_pattern([testpath '/vecAdd*.m'], '%\!test'), ...
%     grep_pattern([testpath '/retVal*.m'], '%\!test'), ...
%     grep_pattern([testpath '/mergeStr*.m'], '%\!test'), ...
%     grep_pattern([testpath '/spVecAdd*.m'], '%\!test'), ...
%     grep_pattern([testpath '/structCopy*.m'], '%\!test')];
% 
% files = regexp(lines, '[\.\/\\\w]+.m', 'match');
% 
% for j=1:length(files)
%     file = files{j};
%     fprintf(1, 'Testing file %s: ', file);
%     mtest(file);
% end
