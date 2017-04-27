function build_mcuda(varargin)
%build_mcuda Build script for the MCUDA submodule

mcudaroot = fileparts(which('startup_mcuda'));
curpath = pwd;
cd(mcudaroot);

opts = m2c_cuda_options;
if isempty(opts)
    warning('build_mcuda:NoCUDA_PATH', 'CUDA_PATH was not set and nvcc is not in path. Compiling without CUDA.\n');
end

try
    % First, compile test scripts
    lines = [grep_pattern('sys/*.m', '\n%#codegen -args') ...
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
