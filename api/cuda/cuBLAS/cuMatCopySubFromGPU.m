function [mat, errCode, toplevel] = cuMatCopySubFromGPU ...
    (nrows, ncols, cuMat, mat, varargin)
% Copies a leading sub-matrix from CUDA to MATLAB.
%
% [mat, errCode] = cuMatCopySubFromGPU(m, n, cuMat, mat)
% copies cuMat(1:nrows, 1:ncols) to MATLAB mat(1:nrows, 1:ncols).
% This is more efficient than creating a submatrix for mat.
%
% [mat, errCode] = cuMatCopySubFromGPU(m, n, cuMat, mat, strm)
% copies in asynchronous mode, where strm is a CuStreamHandle.
% It is important for user not to access or deallocate mat
% before calling cuSynchronize(strm) or another synchronous operation
% on the stream.
%
% SEE ALSO cuMatCopyFromGPU

% Corresponding low-level cuBLAS function:
% cublasStatus_t cublasGetMatrix(int rows, int cols, int elemSize,
%           const void *A, int lda, void *B, int ldb)
% cublasStatus_t cublasGetMatrixAsync(int rows, int cols, int elemSize,
%           const void *A, int lda, void *B, int ldb, cudaStream_t strm)
% http://docs.nvidia.com/cuda/cublas/#cublasgetmatrix

%#codegen -args {m2c_int, m2c_int, CuMat, m2c_mat}
%#codegen cuMatCopySubFromGPU_async -args {m2c_int, m2c_int, CuMat,
%#codegen m2c_mat, CuStreamHandle}

toplevel = nargout>2;
if nargout<1
    % If no output argument, do nothing.
    if  isempty(coder.target) || m2c_debug
        m2c_error('cuMatCopySubFromGPU:NoOutput', ...
            'The output argument mat is required and must be the same as the 4th input.\n');
    end
    return;
end

if (toplevel || m2c_debug)
    if ~isfloat(mat)
        m2c_error('cuMatCopyToGPU:TypeMismatch', 'Expected floating-point numbers.');
    elseif  isreal(mat) && cuMat.type ~= MCU_DOUBLE && cuMat.type ~= MCU_SINGLE || ...
            ~isreal(mat) && cuMat.type ~= MCU_DOUBLE_COMPLEX && cuMat.type ~= MCU_COMPLEX
        m2c_error('cuMatCopyToGPU:TypeMismatch', 'Real and complex numbers mismatch.');
    elseif nrows>size(mat,1) || ncols>size(mat,1)
        m2c_error('cuMatCopyToGPU:SizeMismatch', 'Source matrix is too small.');
    elseif nrows>cuMat.dims(1) || ncols>cuMat.dims(2)
        m2c_error('cuMatCopyToGPU:SizeMismatch', 'Target matrix is too small.');
    end
end

sizepe = cuGetSizePerElement(cuMat.type);

errCode = int32(0); %#ok<NASGU>
if isempty(varargin)
    errCode = coder.ceval('cublasGetMatrix', nrows, ncols, sizepe, ...
        CuMat(cuMat, 'void *'), cuMat.dims(1), ...
        m2c_opaque_ptr(mat, 'void *'), int32(size(mat,1)));
else
    errCode = coder.ceval('cublasGetMatrixAsync', nrows, ncols, sizepe, ...
        CuMat(cuMat, 'void *'), cuMat.dims(1), ...
        m2c_opaque_ptr(mat, 'void *'), int32(size(mat,1)), ...
        CuStreamHandle(varargin{1}));
end

if errCode && (toplevel || m2c_debug)
    m2c_error('CUDA:RuntimeError', 'cublasGetMatrix returned error code %s\n', ...
        cuBlasGetErrorString(errCode));
end

