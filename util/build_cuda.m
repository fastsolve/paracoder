function build_cuda(varargin)
%build_cuda Build script for the CUDA submodule

cudaroot = [m2croot '/api/cuda'];
curpath = pwd;
cd(cudaroot);
opts = m2c_cuda_opts;

if isempty(opts)
    warning('build_cuda:NO_CUDA', 'CUDA_PATH was not set and nvcc is not in path. Compiling without CUDA.\n');
end

lines = [grep_pattern('*.m', '\n%#codegen -args') ...
    grep_pattern('cuBLAS/*.m', '\n%#codegen -args')];
files = regexp(lines, '(\w+.m):', 'tokens');

for j=1:length(files)
    file = files{j}{1};
    try
        m2c(opts{:}, '-mex', '-noinf', '-O', ['-I' cudaroot '/include'], ...
                varargin{:}, file);
    catch ME
        if any(strcmp(varargin, '-force'))
            cd(curpath);
            rethrow(ME)
        end
    end

end

cd(curpath);
