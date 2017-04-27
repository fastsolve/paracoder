% Startup script of MOMP

momproot = fileparts(which('startup_momp'));

addpath(momproot); %#ok<*MCAP>
addpath([momproot '/omp']);
addpath([momproot '/util']);

if ~exist('m2c', 'file')
    run('../M2C/startup.m');
    
    if ~exist(['ompGetMaxThreads.' mexext], 'file')
        fprintf(1, 'To build MOMP, run command build_momp in MATLAB/Octave.\n');
    elseif ~usejava('jvm') || exist('OCTAVE_VERSION', 'builtin')
        load_momp;
    end
end
