function [errCode, toplevel] = cuBlasDestroy(hdl)
%Destroys the cuBLAS context specified by the handle.
%
%  errCode = cuBlasDestroy(hdl)
%
%  SEE ALSO: cuBlasCreate
%
% cuBLAS C interface:
%   cublasStatus_t cublasDestroy(cublasHandle_t handle)

%#codegen -args {CuBlasHandle}

errCode = int32(-1);

if ~isempty(coder.target)
    errCode = coder.ceval('cublasDestroy', CuBlasHandle(hdl));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('CUDA:RuntimeError', 'cublasDestroy returned error code %s\n', cuBlasGetErrorString(errCode));
    end
end
end
