function [errCode, toplevel] = cuBlasSetAtomicsMode(hdl, mode)
%Sets the atomics mode used by the cuBLAS library.
%
%  errCode = cuBlasSetAtomicsMode(hdl, mode) sets the atomics mode to mode,
%  where mode is CUBLAS_ATOMICS_NOT_ALLOWED or CUBLAS_ATOMICS_ALLOWED.
%
%  SEE ALSO: cuBlasGetAtomicsMode
%
% cuBLAS C interface:
%   cublasStatus_t cuBlasSetAtomicsMode(cublasHandle_t handle, cublasAtomicsMode_t mode))

%#codegen -args {CuBlasHandle, m2c_int}

errCode = int32(-1);
if ~isempty(coder.target)
    errCode = coder.ceval('cublasSetAtomicsMode', CuBlasHandle(hdl), mode);
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('cuBlas:RuntimeError', 'cublasSetAtomicsMode returned error code %s\n', ...
            cuBlasGetErrorString(errCode));
    end
end
end
