function [mode, errCode, toplevel] = cuBlasGetPointerMode(hdl)
%Obtains the pointer mode used by the cuBLAS library.
%
%  [mode, errCode] = cuBlasGetPointerMode(hdl)
%  where mode is either CUBLAS_POINTER_MODE_HOST or CUBLAS_POINTER_MODE_DEVICE
%
%  SEE ALSO: cuBlasSetPointerMode
%
% cuBLAS C interface:
%   cublasStatus_t cuBlasGetPointerMode(cublasHandle_t handle, cublasPointerMode_t *mode))

%#codegen -args {CuBlasHandle}

errCode = int32(-1);
if ~isempty(coder.target)
    coder.inline('always');
    t_mode = coder.opaque('cublasPointerMode_t');
    errCode = coder.ceval('cublasGetPointerMode', ...
        CuBlasHandle(hdl), coder.wref(t_mode));
    mode = int32(0); %#ok<NASGU>
    mode = coder.ceval(' ', t_mode);
    toplevel = nargout>2;
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('CUDA:RuntimeError', 'cublasGetPointerMode returned error code %s\n', cuBlasGetErrorString(errCode));
    end
end
end
