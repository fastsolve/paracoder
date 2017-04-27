% Startup script of MCUDA

mcudaroot = fileparts(which('startup_mcuda.m'));

addpath(mcudaroot);
addpath([mcudaroot '/device']);
addpath([mcudaroot '/sys']);
addpath([mcudaroot '/cuBLAS']);
addpath([mcudaroot '/util']);

% Add M2C
if ~exist('m2c', 'file')
    run([fileparts(mcudaroot) '/M2C/startup.m']);
    
    if ~exist(['cuMemcpy.' mexext], 'file')
        fprintf(1, 'To build MCUDA, run command build_mcuda in MATLAB/Octave.\n');
    end
end
