function [errCode, toplevel] = cuVecCopySubToGPU(n, vec, ...
    istart, inc, cuVec, incCuVec, varargin)
% Copies a sub-vector from MATLAB to CUDA
%
% cuVecCopyToGPU(n, vec, istart, inc, cuVec, incCuVec) copies
% vec(istart:inc,iend) in MATLAB to cuVec(1:incCuVec:) on CUDA (in MATLAB
% notation). This is more efficient than using vec(istart:stride:iend).
%
% cuVecCopyToGPU(n, vec, istart, inc, cuVec, incCuVec, strm) copies
% in asynchronous mode, where strm is a CuStreamHandle. It is important
% for user to ensure vec is not changed or deallocated before calling
% cuSynchronize(strm) or another synchronous operation on the stream.
%
% SEE ALSO cuVecCopyToGPU, cuVecCopyFromGPU

% Corresponding low-level cuBLAS function:
% cublasStatus_t cublasSetVector(int n, int elemSize, const void *x, ...
%     int incx, void *y, int incy)
% cublasStatus_t cublasSetVectorAsync(int n, int elemSize, const void *x, ...
%     int incx, void *y, int incy, cudaStream_t strm)
% http://docs.nvidia.com/cuda/cublas/#cublassetvector

%#codegen -args {m2c_int, m2c_vec, m2c_int, m2c_int, CuVec, m2c_int}
%#codegen cuVecCopySubToGPU_async -args {m2c_int, m2c_vec, m2c_int, 
%#codegen m2c_int, CuVec, m2c_int, CuStreamHandle}

toplevel = nargout>1;

if ~isfloat(vec) && m2c_debug
    m2c_error('cuVecCopyToGPU:TypeMismatch', 'Expected floating-point numbers.');
elseif  (isreal(vec) && cuVec.type ~= MCU_DOUBLE && cuVec.type ~= MCU_SINGLE || ...
        ~isreal(vec) && cuVec.type ~= MCU_DOUBLE_COMPLEX && cuVec.type ~= MCU_COMPLEX) && ...
        (toplevel || m2c_debug)
    m2c_error('cuVecCopyToGPU:TypeMismatch', 'Real and complex numbers mismatch.');
elseif n>m2c_intdiv(cuVec.dims(1),incCuVec) && (toplevel || m2c_debug)
    m2c_error('cuVecCopyToGPU:SizeMismatch', 'Target array is too small.');
end

sizepe = mcuGetSizePerElement(cuVec.type);

errCode = int32(0); %#ok<NASGU>
if isempty(varargin)
    errCode = coder.ceval('cublasSetVector', n, sizepe, ...
        m2c_opaque_ptr_const(vec, 'char *', (istart-1)*sizepe), inc, ...
        CuVec(cuVec, 'void *'), incCuVec);
else
    errCode = coder.ceval('cublasSetVectorAsync', n, sizepe, ...
        m2c_opaque_ptr_const(vec, 'char *', (istart-1)*sizepe), inc, ...
        CuVec(cuVec, 'void *'), incCuVec, CuStreamHandle(varargin{1}));
end

if errCode && (toplevel || m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cublasSetVector returned error code %s\n', cuBlasGetErrorString(errCode));
end
