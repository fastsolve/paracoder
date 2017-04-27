function [errCode, toplevel] = cuDeviceReset
%Waits until all preceding commands in all streams of all host threads have completed.
%
% errCode = cuDeviceReset
%
% The eror code is checked automatically when cuGetDevice is a top-level
% function or is compiled with debugging.
%
% See also cuStreamSynchronize, cuThreadSynchronize

%#codegen -args {}

errCode = int32(-1);
if isempty(coder.target); return; end

coder.inline('always');
errCode = coder.ceval('cudaDeviceReset');

toplevel = nargout>1;
if errCode && (toplevel || nargout<1 && m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaDeviceReset returned error code %s\n', ...
        cuGetErrorString(errCode));
end
