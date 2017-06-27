% Startup script for M2C.
if exist('OCTAVE_VERSION', 'builtin')
    more off;
else
    warning('off', 'MATLAB:mex:GccVersion');
    warning('off', 'MATLAB:mex:GccVersion_link');
end

load_m2c;
