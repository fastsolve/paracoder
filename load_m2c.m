% Startup script for loading M2C.
% The script must be run in the M2C Root directory.

m2croot = fileparts(which('load_m2c.m'));

warning('off', 'MATLAB:pfileOlderThanMfile');
warning('off', 'MATLAB:mex:GccVersion')

addpath(m2croot); %#ok<*MCAP>
addpath([m2croot '/util']);
addpath([m2croot '/api']);
addpath([m2croot '/api/ctypes']);
addpath([m2croot '/api/mtypes']);
addpath([m2croot '/api/mpi4m']);
addpath([m2croot '/api/mpi4m/mpi']);
addpath([m2croot '/api/omp4m']);
addpath([m2croot '/api/multicore']);
addpath([m2croot '/api/cuda']);
addpath([m2croot '/api/cuda/cuBLAS']);

if ~exist('coder.p', 'file')
    addpath([m2croot '/opts/No_coder']);
    
    if isoctave
        % Add path for Octave
        addpath([m2croot '/util/octave']);
        addpath([m2croot '/opts/No_coder/octave']);
        more('off');
    end
end
