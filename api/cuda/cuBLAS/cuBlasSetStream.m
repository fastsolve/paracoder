function [errCode, toplevel] = cuBlasSetStream(hdl, strm)
%Sets the cudaStream used by the cuBLAS library.
%
%  errCode = cuBlasSetStream(hdl, strm) sets the stream to strm.
%
%  SEE ALSO: cuBlasGetStream
%
% cuBLAS C interface:
%   cublasStatus_t cuBlasSetStream(cublasHandle_t handle, cudaStream_t strm))

%#codegen -args {CuBlasHandle, CuStreamHandle}

errCode = int32(-1);
if ~isempty(coder.target)
    errCode = coder.ceval('cublasSetStream', CuBlasHandle(hdl), CuStreamHandle(strm));
    
    toplevel = nargout>1;
    if errCode && (toplevel || m2c_debug)
        m2c_error('cuBlas:RuntimeError', 'cublasSetStream returned error code %s\n', ...
            cuBlasGetErrorString(errCode))
    end
end
end
