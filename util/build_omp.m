function build_omp(varargin)
%BUILD_OMP Build script for OpenMP functions.

omproot = [m2croot '/api/omp4m'];

curpath = pwd;
cd(omproot);

lines = grep_pattern('omp*.m', '\n%#codegen -args');
files = regexp(lines, '[\w\\\/]+\.m', 'match');

for j=1:length(files)
    file = files{j};
    try
        m2c('-omp', '-mex', '-O', varargin{:}, file);
    catch ME
        if any(strcmp(varargin, '-force'))
            cd(curpath);
            rethrow(ME)
        end
    end
end

cd(curpath);
