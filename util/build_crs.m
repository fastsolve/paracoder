function build_crs(varargin)
%BUILD_CRS Build script for CRS

crsroot = [m2croot '/api/crs'];

curpath = pwd;
cd(crsroot);

try
    lines = grep_pattern('crs*.m', '\n%#codegen -args');
    files = regexp(lines, '[\w\\\/]+\.m', 'match');

    for j=1:length(files)
        file = files{j};
        m2c('-mex', '-omp', '-O', varargin{:}, file);
    end
catch ME
    cd(curpath);
    rethrow(ME);
end

cd(curpath);
