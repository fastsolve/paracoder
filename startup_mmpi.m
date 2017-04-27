% Startup script of MMPI

mmpi_root = fileparts(which('startup_mmpi.m'));

addpath(mmpi_root); %#ok<*MCAP>
addpath([mmpi_root '/mpi']);
addpath([mmpi_root '/util']);

if ~exist('m2c', 'file') && exist('../M2C', 'dir')
    % Start up M2C from its root directory
    run ../M2C/startup

    if ~exist(['mpi_Waitall.' mexext], 'file')
        fprintf(1, 'To build MMP, run command build_mmpi in MATLAB/Octave.\n');
    else
        load_mmpi;
    end
end
