function [cuMat, errCode] = cuMatCopyToGPU(mat, cuMat, varargin)
% Copies a dense matrix from MATLAB to CUDA.
%
% [cuMat, errCode] = cuMatCopyToGPU(mat) copies the whole array from
% mat in MATLAB to a new matrix cuMat on CUDA. The matrix cuMat
% must be destroied by calling cuMatDestroy after use.
%
% cuMatCopyToGPU(mat, cuMat) copies the whole array from mat in MATLAB
% to cuMat on CUDA.
%
% cuMatCopyToGPU(mat, cuMat, cuStream) copies the whole array in
% asynchronous mode. It is the user's responsibility  to ensure mat is
% not changed or deallocated before calling cuSynchronize or another
% synchronous operation on the stream.
%
% SEE ALSO cuMatCopyFromGPU, cuMatCopySubToGPU, cuMatDestroy

if nargout<1 && nargin<2
    if  isempty(coder.target) || m2c_debug
        m2c_warn('cuMatCopyToGPU:NoGPUHandle', 'You must specify a cuMat handle.\n');
    end
    return;
end

if nargin==1
    type = cuType(class(mat), isreal(mat));
    cuMat = cuMatCreate(int32(size(mat,1)), int32(size(mat,2)), type);
end

errCode = cuMatCopySubToGPU(int32(size(mat,1)), int32(size(mat,2)), mat, cuMat, varargin{:});

function test %#ok<DEFNU>
%!shared m, n, A
%!test
%! m=int32(200); n=int32(100);
%! A =rand(m,n);
%! cuda_A = cuMatCopyToGPU(A);
%! B = cuMatCopyFromGPU(cuda_A);
%! cuMatDestroy(cuda_A);
%! assert(isequal(A, B));

%!test
%! cuda_A = cuMatCopyToGPU(A);
%! strm = cuStreamHandleCreate();
%! cuMatCopyToGPU(A, cuda_A, strm);
%! B = zeros(m, n);
%! B = cuMatCopyFromGPU(cuda_A, B, strm);
%! cuSynchronize(strm);
%! cuMatDestroy(cuda_A);
%! cuStreamHandleDestroy(strm);
%! assert(isequal(A, B));
