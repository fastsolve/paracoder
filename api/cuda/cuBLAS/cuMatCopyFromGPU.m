function [mat, errCode] = cuMatCopyFromGPU(cuMat, mat, varargin)
% Copies a dense matrix from CUDA to MATLAB.
%
% mat = cuMatCopyFromGPU(cuMat) allocates mat in MATLAB
% and then copies cuMat on CUDA device to it.  The size to be copied
% is given by cuMat.dims. In code-generation mode, cuMat.type must be
% a constant at compile time.
%
% [mat, errCode] = cuMatCopyFromGPU(cuMat, mat) copies the whole matrix
% from cuMat on CUDA device to mat in MATLAB.
%
% mat = cuMatCopyFromGPU(cuMat, mat, strm) copies in asynchronous mode,
% where strm is a CuStreamHandle. It is important for user not to access
% or deallocate mat before calling cuSynchronize(strm) or another
% synchronous operation on the stream.
%
% Note that in the last two modes, the output argument must be the same
% as the second input argument.
%
% SEE ALSO cuMatCopySubFromGPU, cuMatCopySubToGPU

narginchk(1, 3);

if nargin==1
    mat = zeros(cuMat.dims, 'like', mcuZero(cuMat.type));
end

[mat, errCode] = cuMatCopySubFromGPU(cuMat.dims(1), cuMat.dims(2), ...
    cuMat, mat, varargin{:});
