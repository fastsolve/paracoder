function opts = m2c_cuda_opts
% Try to locate CUDA automatically using CUDA_PATH or path for nvcc.
% The output is either {}, {'-cuda'}, or {'-cuda', {CUDAPATH}}, which
% can be passed as arguments to m2c using m2c(opts{:}, ...)

persistent opts__;

if isempty(opts__) && ~iscell(opts__)
    if getenv('CUDA_PATH')
        opts__ = {'-cuda'};
    else
        [~, result] = system('which nvcc');
        if ~isempty(strtrim(result)) && ~strfind(result, 'not found')
            cuda_dir = fileparts(fileparts(strtrim(result)));
            opts__ = {'-cuda', ['{''' cuda_dir '''}']};
        else
            opts__ = {};
        end
    end
end

opts = opts__;