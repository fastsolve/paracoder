% Startup script for M2C.
% The script must be run in the M2C Root directory.

warning('off', 'MATLAB:pfileOlderThanMfile');
warning('off', 'MATLAB:mex:GccVersion')

if exist('m2c', 'file')~=2
    addpath(pwd); %#ok<*MCAP>
    addpath([pwd '/util']);
    addpath([pwd '/ctypes']);
end

if ~exist('coder.p', 'file')
    addpath([pwd '/No_coder']);
end
