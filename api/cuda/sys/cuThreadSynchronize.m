function [errCode, toplevel] = cuThreadSynchronize
%Blocks until the device has completed all preceding requested tasks.
%
% errCode = cuThreadSynchronize
%
% The eror code is checked automatically when cuGetThread is a top-level
% function or is compiled with debugging.
%
% See also cuDeviceSynchronize, cuStreamSynchronize

%#codegen -args {}

errCode = int32(-1);
if isempty(coder.target); return; end

coder.inline('always');
errCode = coder.ceval('cudaThreadSynchronize');

toplevel = nargout>1;
if errCode && (toplevel || nargout<1 && m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaThreadSynchronize returned error code %s\n', ...
        cuGetErrorString(errCode));
end
