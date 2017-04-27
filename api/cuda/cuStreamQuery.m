function notReady = cuStreamQuery(stm)
%Returns 0 if all operations in stream have completed, or cudaErrorNotReady if not.
%
%  notReady = cuStreamQuery(stm)
%
%  SEE ALSO: cuStreamQuery, cuDeviceQuery
%
% CUDA C interface:
%   cudaError_t cuStreamQuery(cuStreamHandle_t handle)

%#codegen -args {CuStreamHandle}

notReady = int32(-1);

if isempty(coder.target); return; end

coder.inline('always');
notReady = coder.ceval('cudaStreamQuery', CuStreamHandle(stm));
