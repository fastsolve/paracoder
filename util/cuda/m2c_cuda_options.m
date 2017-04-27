function opts = m2c_cuda_options
% Try to locate CUDA automatically using CUDA_PATH or path for nvcc.
% The output is either {}, {'-cuda'}, or {'-cuda', {CUDAPATH}}, which
% can be passed as arguments to m2c using m2c(opts{:}, ...)

if getenv('CUDA_PATH')
    opts = {'-cuda'};
else
    [~, result] = system('which nvcc');
    if ~isempty(strtrim(result))
        cuda_dir = fileparts(fileparts(strtrim(result)));
        opts = {'-cuda', ['{''' cuda_dir '''}']};
    else        
        opts = {};
    end
end
