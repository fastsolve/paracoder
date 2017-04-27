function [mode, errCode, toplevel] = cuBlasGetAtomicsMode(hdl)
%Obtains the atomics mode used by the cuBLAS library.
%
%  [mode, errCode] = cuBlasGetAtomicsMode(hdl)
%  where mode is either CUBLAS_ATOMICS_ALLOWED or CUBLAS_ATOMICS_NOT_ALLOWED.
%
%  SEE ALSO: cuBlasSetAtomicsMode
%
% cuBLAS C interface:
%   cublasStatus_t cuBlasGetAtomicsMode(cublasHandle_t handle, cublasAtomicsMode_t *mode))

%#codegen -args {CuBlasHandle}

errCode = int32(-1);
if ~isempty(coder.target)
    t_mode = coder.opaque('cublasAtomicsMode_t');
    errCode = coder.ceval('cublasGetAtomicsMode', ...
        CuBlasHandle(hdl), coder.wref(t_mode));
    mode = int32(0); %#ok<NASGU>
    mode = coder.ceval(' ', t_mode);
    toplevel = nargout>2;
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('CUDA:RuntimeError', 'cublasGetAtomicsMode returned error code %s\n', cuBlasGetErrorString(errCode));
    end
end
end
