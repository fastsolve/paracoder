function build_mpi(varargin)

mpiroot = [m2croot '/api/mpi4m'];

curpath = pwd;
cd(mpiroot);

lines = [grep_pattern('util/*.m', '\n%#codegen\s+-args') ...
         grep_pattern('mpi/*.m', '\n%#codegen\s+-args')];
files = regexp(lines, '([\.\/\\\w]+.m):', 'tokens');

for j=1:length(files)
    file = files{j}{1};
    try
        m2c('-mpi', '-O', '-mex', varargin{:}, file);
    catch ME
        if any(strcmp(varargin, '-force'))
            cd(curpath);
            rethrow(ME)
        end
    end
end

cd(curpath);
