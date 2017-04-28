function build_m2c(varargin)

if isoctave
    mex = @mmex;
end

funcs = {'m2c_opaque_ptr', 'm2c_opaque_ptr_const'};

% Compile m2c_opaque_ptr and m2c_opaque_ptr_const
for j=1:length(funcs)
    dir = fileparts(which([funcs{j} '.m']));
    if ~isnewer([dir '/' funcs{j} '.' mexext], [dir '/' funcs{j} '.m'])
        mex([dir '/' funcs{j} '.c'], '-output', ...
            [dir '/' funcs{j} '.' mexext]);
        if isoctave
            delete([funcs{j} '.o'])
        end
    end
end

% Build OpenMP
build_omp(varargin{:})

% Build MPI
build_mpi(varargin{:})

if ~isempty(m2c_cuda_opts)
    % Build CUDA
    build_cuda(varargin{:})
end
