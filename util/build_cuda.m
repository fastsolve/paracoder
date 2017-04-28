function build_cuda(varargin)
%build_cuda Build script for the CUDA submodule

mcudaroot = [m2croot '/api/cuda'];
curpath = pwd;
cd(mcudaroot);
opts = m2c_cuda_opts;

if isempty(opts)
    warning('build_mcuda:NO_CUDA', 'CUDA_PATH was not set and nvcc is not in path. Compiling without CUDA.\n');
end

try
    lines = [grep_pattern('*.m', '\n%#codegen -args') ...
        grep_pattern('cuBLAS/*.m', '\n%#codegen -args')];
    files = regexp(lines, '(\w+.m):', 'tokens');
    
    for j=1:length(files)
        file = files{j}{1};
        m2c(opts{:}, '-mex', '-noinf', '-O', ['-I' mcudaroot '/include'], ...
            varargin{:}, file);
    end
catch ME
    cd(curpath);
    rethrow(ME)
end

cd(curpath);
