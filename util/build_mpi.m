function build_mpi(varargin)

mpiroot = [m2croot '/api/mpi4m'];

curpath = pwd;
cd(mpiroot);

try
    lines = [grep_pattern('util/*.m', '\n%#codegen\s+-args') ...
             grep_pattern('mpi/*.m', '\n%#codegen\s+-args')];
    files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');

    for j=1:length(files)
        file = files{j}{1};
        m2c('-mpi', '-O', '-mex', varargin{:}, file);
    end
catch ME
    cd(curpath);
    rethrow(ME);
end

cd(curpath);
