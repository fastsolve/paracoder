% Startup script for loading M2C.
% The script must be run in the M2C Root directory.

warning('off', 'MATLAB:pfileOlderThanMfile');
warning('off', 'MATLAB:mex:GccVersion')

addpath(m2croot); %#ok<*MCAP>
addpath([m2croot '/util']);
addpath([m2croot '/api']);
addpath([m2croot '/api/ctypes']);
addpath([m2croot '/api/mtypes']);

% Add path for matrix operations
addpath([m2croot '/api/crs']);

% Add path for mesh operations
addpath([m2croot '/api/mesh/ahf']);

% Add path for MPI
addpath([m2croot '/api/mpi4m']);
addpath([m2croot '/api/mpi4m/mpi']);
addpath([m2croot '/api/mpi4m/util']);

% Add path for OpenMP
addpath([m2croot '/api/multicore']);
addpath([m2croot '/api/omp4m']);

if ~isempty(m2c_cuda_opts)
    % Add path for CUDA
    addpath([m2croot '/api/cuda']);
    addpath([m2croot '/api/cuda/cuBLAS']);
end

% Add dummy API if Coder does not exist
if ~exist('coder.p', 'file')
    addpath([m2croot '/opts/No_coder']);
end

if isoctave
    % Initialize OpenMP
    if isempty(getenv('OMP_NUM_THREADS'))
        fprintf(1, 'Set OMP_NUM_THREADS to %d.\n', nproc);
        setenv('OMP_NUM_THREADS', int2str(nproc));
    end

    addpath([m2croot '/util/octave']);
    addpath([m2croot '/opts/No_coder/octave']);
end
