% Startup script for M2C.
% The script must be run in the M2C Root directory.

m2croot = fileparts(which('startup_m2c.m'));

warning('off', 'MATLAB:pfileOlderThanMfile');
warning('off', 'MATLAB:mex:GccVersion')

addpath(m2croot); %#ok<*MCAP>
addpath([m2croot '/util']);
addpath([m2croot '/api']);
addpath([m2croot '/api/ctypes']);
addpath([m2croot '/api/mtypes']);
addpath([m2croot '/api/multicore']);
addpath([m2croot '/api/omp']);

if ~exist('coder.p', 'file')
    addpath([m2croot '/api/No_coder']);
    
    if exist('OCTAVE_VERSION', 'builtin')
        % If using Octave, add the Octave path
        addpath([m2croot '/util/octave']);
        addpath([m2croot '/api/octave']);
        more('off');
    end
end

% Make sure m2c_opaque_ptr and m2c_opaque_ptr_const are compiled
if ~exist(['m2c_opaque_ptr.' mexext], 'file')
    m2c_opaque_ptr;
end
if ~exist(['m2c_opaque_ptr_const.' mexext], 'file')
    m2c_opaque_ptr_const;
end

