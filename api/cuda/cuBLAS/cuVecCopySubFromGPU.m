function [vec, errCode, toplevel] = cuVecCopySubFromGPU(n, cuVec, ...
    incCuVec, vec, istart, inc, varargin)
% Copies a sub-vector from CUDA to MATLAB.
%
% [vec, errCode] = cuVecCopySubFromGPU(n, cuVec, incCuVec, vec, istart, inc)
% copies cuVec(1:incCurVec:incCurVec*len) to MATLAB vec(istart:inc:).
% This is more efficient than creating a subvector for vec.
%
% [vec, errCode] = cuVecCopySubFromGPU(n, cuVec, incCuVec, vec, istart,
% inc, strm) copies from cuVec to vec in MATLAB in asynchronous mode,
% where strm is a CuStreamHandle. It is important for user not to access
% or deallocate vec before calling cuSynchronize(strm) or another
% synchronous operation on the stream.
%
% SEE ALSO cuVecCopyFromGPU

% Corresponding low-level cuBLAS function:
% cublasStatus_t cublasGetVector(int n, int elemSize,
%     const void *x, int incx, void *y, int incy)
% cublasStatus_t cublasGetVectorAsyn(int n, int elemSize,
%     const void *x, int incx, void *y, int incy, cudaStream_t strm)
% http://docs.nvidia.com/cuda/cublas/#cublasgetvector

%#codegen -args {m2c_int, CuVec, m2c_int, m2c_vec, m2c_int, m2c_int}
%#codegen cuVecCopySubFromGPU_async -args {m2c_int, CuVec, m2c_int,
%#codegen m2c_vec, m2c_int, m2c_int, CuStreamHandle}

toplevel = nargout>2;
if nargout<1
    % If no output argument, do nothing.
    if  isempty(coder.target) || m2c_debug
        m2c_error('cuVecCopySubFromGPU:NoOutput', ...
            'The output argument vec is required and must be the same as the 4th input.\n');
    end
    return;
end

if toplevel || m2c_debug
    if ~isfloat(vec)
        m2c_error('cuVecCopyToGPU:TypeMismatch', 'Expected floating-point numbers.');
    elseif  isreal(vec) && cuVec.type ~= MCU_DOUBLE && cuVec.type ~= MCU_SINGLE || ...
            ~isreal(vec) && cuVec.type ~= MCU_DOUBLE_COMPLEX && cuVec.type ~= MCU_COMPLEX
        m2c_error('cuVecCopyToGPU:TypeMismatch', 'Real and complex numbers mismatch.');
    elseif n>m2c_intdiv(int32(length(vec)),inc)
        m2c_error('cuVecCopyToGPU:SizeMismatch', 'Target array is too small.');
    end
end

sizepe = mcuGetSizePerElement(cuVec.type);
errCode = int32(0); %#ok<NASGU>
if isempty(varargin)
    errCode = coder.ceval('cublasGetVector', n, sizepe, ...
        CuVec(cuVec, 'void *'), incCuVec, ...
        m2c_opaque_ptr(vec, 'char *', (istart-1)*sizepe), inc);
else
    errCode = coder.ceval('cublasGetVectorAsync', n, sizepe, ...
        CuVec(cuVec, 'void *'), incCuVec, ...
        m2c_opaque_ptr(vec, 'char *', (istart-1)*sizepe), inc, ...
        CuStreamHandle(varargin{1}));
end

if errCode && (toplevel || m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cublasGetVector returned error code %s\n', ...
        cuBlasGetErrorString(errCode));
end
