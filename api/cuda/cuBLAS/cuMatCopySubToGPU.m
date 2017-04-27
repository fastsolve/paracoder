function [errCode, toplevel] = cuMatCopySubToGPU ...
    (nrows, ncols, mat, cuMat, varargin)
% Copies a leading sub-matrix from MATLAB to CUDA.
%
% cuMatCopySubFromGPU(m, n, mat, cuMat) copies mat(1:nrows, 1:ncols) in
% MATLAB to cuMat(1:nrows, 1:ncols) on CUDA. This may be more efficient
% than creating a submatrix for mat.
%
% cuMatCopySubFromGPU(m, n, mat, cuMat, strm) copies in asynchronous mode,
% where strm is a CuStreamHandle. It is important for user to ensure mat
% is not changed or deallocated before calling cuSynchronize(strm) or
% another synchronous operation on the stream.
%
% SEE ALSO cuMatCopyToGPU, cuMatCopyFromGPU

% Corresponding low-level cuBLAS function:
% cublasStatus_t cublasSetMatrix(int rows, int cols, int elemSize,
%       const void *A, int lda, void *B, int ldb)
% cublasStatus_t cublasSetMatrixAsync(int rows, int cols, int elemSize,
%       const void *A, int lda, void *B, int ldb, cudaStream_t strm)
% http://docs.nvidia.com/cuda/cublas/#cublassetmatrix

%#codegen -args {m2c_int, m2c_int, m2c_mat, CuMat}
%#codegen cuMatCopySubToGPU_async -args {m2c_int, m2c_int, m2c_mat, CuMat, CuStreamHandle}

toplevel = nargout>1;

if (toplevel || m2c_debug)
    if ~isfloat(mat)
        m2c_error('cuMatCopyToGPU:TypeMismatch', 'Expected floating-point numbers.');
    elseif  isreal(mat) && cuMat.type ~= MCU_DOUBLE && cuMat.type ~= MCU_SINGLE || ...
            ~isreal(mat) && cuMat.type ~= MCU_DOUBLE_COMPLEX && cuMat.type ~= MCU_COMPLEX
        m2c_error('cuMatCopyToGPU:TypeMismatch', 'Real and complex numbers mismatch.');
    elseif nrows>size(mat,1) || ncols>size(mat,1)
        m2c_error('cuMatCopyToGPU:SizeMismatch', 'Target matrix is too small.');
    elseif nrows>cuMat.dims(1) || ncols>cuMat.dims(2)
        m2c_error('cuMatCopyToGPU:SizeMismatch', 'Sourcd matrix is too small.');
    end
end

sizepe = mcuGetSizePerElement(cuMat.type);

errCode = int32(0); %#ok<NASGU>
if isempty(varargin)
    errCode = coder.ceval('cublasSetMatrix', nrows, ncols, sizepe, ...
        m2c_opaque_ptr(mat, 'void *'), int32(size(mat,1)), ...
        CuMat(cuMat, 'void *'), cuMat.dims(1));
else
    errCode = coder.ceval('cublasSetMatrixAsync', nrows, ncols, sizepe, ...
        m2c_opaque_ptr(mat, 'void *'), int32(size(mat,1)), ...
        CuMat(cuMat, 'void *'), cuMat.dims(1), CuStreamHandle(varargin{1}));
end

if errCode && (toplevel || m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cublasSetMatrix returned error code %s\n', ...
        cuBlasGetErrorString(errCode));
end

