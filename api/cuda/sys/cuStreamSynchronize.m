function [errCode, toplevel] = cuStreamSynchronize(stm)
%Waits until all preceding commands in the given stream have completed.
%
%  errCode = cuStreamSynchronize(stm)
%
%  SEE ALSO: cuStreamQuery, cuDeviceSynchronize, cuThreadSynchronize
%
% CUDA C interface:
%   cudaError_t cuStreamSynchronize(cuStreamHandle_t handle)

%#codegen -args {CuStreamHandle}

errCode = int32(-1);

if isempty(coder.target); return; end

coder.inline('always');
errCode = coder.ceval('cudaStreamSynchronize', CuStreamHandle(stm));

toplevel = nargout>1;
if errCode && (toplevel || nargout<1 && m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaStreamSynchronize returned error code %s\n', ...
        cuGetErrorString(errCode));
end
