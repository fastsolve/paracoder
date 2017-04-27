function [stm, errCode, toplevel] = cuStreamHandleCreate
%Creates a new asynchronous stream.
%
%  [stm, errCode] = cuStreamHandleCreate
%
%  SEE ALSO: cuSynchronize, cuStreamHandleDestroy
%
% CUDA C interface:
%   cuError_t cudaStreamCreate(cudaStream_t *handle)

%#codegen -args {}

errCode = int32(-1);

if ~isempty(coder.target)
    t_stm = coder.opaque('cudaStream_t');
    errCode = coder.ceval('cudaStreamCreate', coder.wref(t_stm));
    
    toplevel = nargout>2;
    stm = CuStreamHandle(t_stm, toplevel);
    
    if errCode && (toplevel || nargout<2 && m2c_debug)
        m2c_error('CUDA:RuntimeError', 'cudaStreamCreate returned error code %s\n', cuGetErrorString(errCode));
    end
end
end
