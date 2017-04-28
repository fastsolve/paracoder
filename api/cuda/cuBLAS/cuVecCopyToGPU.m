function [cuVec, errCode] = cuVecCopyToGPU(vec, cuVec, varargin)
% Copies a vector from MATLAB to CUDA
%
% [cuVec, errCode] = cuVecCopyToGPU(vec) copies the whole array from
% vec in MATLAB to a new vector cuVec on CUDA. The vector
% cuVec must be destroied by calling cuVecDestroy after use.
%
% cuVecCopyToGPU(vec, cuVec) copies the whole array from vec in MATLAB
% to cuVec on CUDA.
%
% cuVecCopyToGPU(vec, cuVec, cuStream) copies in asynchronous mode,
% where cuStream is a CuStreamHandle. It is important for user to 
% ensure vec is not changed or deallocated before calling
% cuSynchronize(strm) or another synchronous operation on the stream.
%
% SEE ALSO cuVecCopyFromGPU, cuVecCopySubToGPU, cuVecDestroy

if nargout<1 && nargin<2
    if  isempty(coder.target) || m2c_debug
        m2c_warn('cuVecCopyToGPU:NoGPUHandle', ...
            'You must specify a cuVec handle.\n');
    end
    return;
end

if size(vec,2)~=1 && (isempty(coder.target) || m2c_debug)
    m2c_warn('cuVecCopyToGPU:NotVector', 'First input should be a column vector.\n');
end

if nargin==1
    type = cuType(class(vec), isreal(vec));
    cuVec = cuVecCreate(int32(size(vec,1)), type);
end

errCode = cuVecCopySubToGPU(int32(length(vec)), vec, ...
    int32(1), int32(1), cuVec, int32(1), varargin{:});

function test %#ok<DEFNU>
%!shared m, x
%!test
%! m=int32(1000000);
%! x =rand(m,1);
%! cuda_x = cuVecCopyToGPU(x);
%! y = cuVecCopyFromGPU(cuda_x);
%! cuVecDestroy(cuda_x);
%! assert(isequal(x, y));

%!test
%! cuda_x = cuVecCreate(m);
%! strm = cuStreamHandleCreate();
%! cuVecCopyToGPU(x, cuda_x, strm);
%! y = zeros(m, 1);
%! y = cuVecCopyFromGPU(cuda_x, y, strm);
%! cuSynchronize(strm);
%! cuVecDestroy(cuda_x);
%! cuStreamHandleDestroy(strm);
%! assert(isequal(x, y));
