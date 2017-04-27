function build_omp(varargin)
%BUILD_OMP Build script for OpenMP functions.

omproot = [m2croot '/api/omp4m'];

curpath = pwd;
cd(omproot);

try
    % First, compile omp commands
    lines = grep_pattern('omp*.m', '\n%#codegen -args');
    files = regexp(lines, '[\w\\\/]+\.m', 'match');
    
    for j=1:length(files)
        file = files{j};
        m2c('-omp', '-mex', '-O', varargin{:}, file);
    end
catch ME
    cd(curpath);
    rethrow(ME);
end

cd(curpath);
