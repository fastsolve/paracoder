% Startup script for M2C.
% The script must be run in the current directory.

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
            error('You must build M2C before using MPI.');
        else
            build_m2c;
        end
    end
else
    try
        build_m2c;
    catch
        warning('Could not build M2C.');
    end
end
