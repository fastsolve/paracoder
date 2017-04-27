function [strm, errCode, toplevel] = cuBlasGetStream(cubHdl)
%Obtains the cudaStream used by the cuBLAS library.
%
%  [strm, errCode] = cuBlasGetStream(cubHdl)
%
%  SEE ALSO: cuBlasSetStream
%
% cuBLAS C interface:
%   cublasStatus_t cuBlasGetStream(cublasHandle_t handle, cudaStream_t *strm))

%#codegen -args {CuBlasHandle}

toplevel = nargout>2;

errCode = int32(-1);
if ~isempty(coder.target)
    t_strm = coder.opaque('cudaStream_t');
    errCode = coder.ceval('cublasGetStream', ...
        CuBlasHandle(cubHdl), coder.wref(t_strm));
    strm = CuStreamHandle(t_strm, toplevel);
    
    if errCode && (toplevel || m2c_debug)
        m2c_error('CUDA:RuntimeError', 'cublasGetStream returned error code %s\n', ...
            cuBlasGetErrorString(errCode));
    end
end
end
