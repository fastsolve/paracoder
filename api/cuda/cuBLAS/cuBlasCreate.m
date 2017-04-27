function [hdl, errCode, toplevel] = cuBlasCreate
%Initializes CUBLAS and creates a handle to the CUBLAS library context.
%
%  [hdl, errCode] = cuBlasCreate
%
%  SEE ALSO: cuBlasDestroy
%
% cuBLAS C interface:
%   cublasStatus_t cublasCreate(cublasHandle_t *handle)

%#codegen -args {}

errCode = int32(-1);

if ~isempty(coder.target)
    t_hdl = coder.opaque('cublasHandle_t');
    errCode = coder.ceval('cublasCreate', coder.wref(t_hdl));
    
    toplevel = nargout>2;
    hdl = CuBlasHandle(t_hdl, toplevel);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('CUDA:RuntimeError', 'cublasCreate returned error code %s\n', cuBlasGetErrorString(errCode));
    end
end
end
