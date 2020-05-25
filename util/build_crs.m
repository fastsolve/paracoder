function build_crs(varargin)
%BUILD_CRS Build script for CRS

apiroot = [m2croot '/api'];

curpath = pwd;
cd(apiroot);

lines = [grep_pattern('crs/crs*.m', '\n%#codegen -args'), ...
    grep_pattern('ccs/ccs*.m', '\n%#codegen -args'), ...
    grep_pattern('dense/solve/*.m', '\n%#codegen -args')];
files = regexp(lines, '[\w\\\/]+\.m', 'match');

for j=1:length(files)
    file = files{j};
    try
        m2c('-mex', '-omp', '-O', varargin{:}, file);
    catch ME
        if any(strcmp(varargin, '-force'))
            cd(curpath);
            rethrow(ME);
        end
    end
end

cd(curpath);
