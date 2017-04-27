function build_momp(varargin)
%BUILD_MOMP Build script for MOMP functions.

momproot = fileparts(which('startup_momp'));
curpath = pwd;
cd(momproot);

try
    % First, compile test scripts
    lines = grep_pattern('omp/omp*.m', '\n%#codegen -args');
    files = regexp(lines, '[\w\\\/]+\.m', 'match');
    
    for j=1:length(files)
        file = files{j};
        m2c('-omp', '-mex', '-O', varargin{:}, file);
    end
catch ME
    cd(curpath);
    rethrow(ME);
end

load_momp;
cd(curpath);
