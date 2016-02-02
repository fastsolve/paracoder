% Startup script for M2C.
% The script must be run in the current directory.

warning('off', 'MATLAB:pfileOlderThanMfile');
warning('off', 'MATLAB:mex:GccVersion') 

if exist('m2c', 'file')~=2
    addpath(pwd); %#ok<*MCAP>
    addpath([pwd '/util']);
end

if ~exist('coder.p', 'file')
    addpath([pwd '/No_coder']);
end

if isinmpi
    if ~exist(['./opaque_ptr.', mexext], 'file')
        if ~ismpiroot
            error('You must build M2C before using mpirun/mpiexec.');
        else
            build_m2c;
        end
        exit;
    end
else
    try
        build_m2c;
    catch
        error('Could not build M2C.');
    end
end
