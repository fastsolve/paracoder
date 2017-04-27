function [errCode, toplevel] = cuStreamHandleDestroy(stm)
%Destroys and cleans up the asynchronous stream specified by the name.
%
%  errCode = cuStreamHandleDestroy(stm)
%
%  SEE ALSO: cuStreamHandleCreate
%
% CUDA C interface:
%   cudaError_t cudaStreamDestroy(cuStreamHandle_t handle)

%#codegen -args {CuStreamHandle}

errCode = int32(-1);

if isempty(coder.target); return; end

coder.inline('always');
errCode = coder.ceval('cudaStreamDestroy', CuStreamHandle(stm));

toplevel = nargout>1;
if errCode && (toplevel || nargout<1 && m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cudaStreamDestroy returned error code %s\n', cuGetErrorString(errCode));
end