function test_momp(varargin)
%TEST_MOMP Test script for running all the tests of MOMP

% Obtain all the files containing "%!test" in test directory
if exist('./test_momp.m', 'file')
    lines = grep_pattern('*.m', '\n%\!test');
else
    lines = grep_pattern('test/*.m', '\n%\!test');
end
files = regexp(lines, '[\/\\\w]+.m', 'match');

for j=1:length(files)
    file = files{j};
    fprintf('Testing %s... ', file);
    
    % Test the program
    test_mcode(file);
end
