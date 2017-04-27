function build_tests(varargin)

momproot = fileparts(which('startup_momp'));
curpath = pwd;
cd(momproot);

try
    lines = grep_pattern('test/*.m', '\n%#codegen -args');
    files = regexp(lines, '(\w+.m):', 'tokens');
    
    for j=1:length(files)
        file = files{j}{1};
        m2c('-omp', '-O', '-mex', varargin{:}, file);
    end
catch ME
    cd(curpath);
    rethrow(ME);
end

cd(curpath);
