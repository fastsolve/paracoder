function [vec, errCode, toplevel] = cuVecCopyFromGPU(cuVec, vec, varargin)
% Copies a vector from CUDA to MATLAB.
%
% [vec, errCode] = cuVecCopyFromGPU(cuVec) allocates vec in MATLAB
% and then copies cuVec on CUDA device to it. The length to be copied
% is equal to cuVec.dims(1). In code-generation mode, cuVec.type must be
% a constant at compile time.
%
% vec = cuVecCopyFromGPU(cuVec, vec) copies the whole array
% from cuVec on CUDA device to vec in MATLAB.
%
% vec = cuVecCopyFromGPU(cuVec, vec, strm) copies in asynchronous mode,
% where strm is a CuStreamHandle. It is important for user not to access
% or deallocate vec before calling cuSynchronize(strm) or another
% synchronous operation on the stream.
%
% Note that the output argument vec is required, and it must be the
% same as the second input argument in the last two modes.
%
% SEE ALSO cuVecCopySubFromGPU, cuVecCopySubToGPU

toplevel = nargout>2;
if nargout<1
    % If no output argument, do nothing.
    if  isempty(coder.target) || m2c_debug
        m2c_error('cuVecCopyFromGPU:NoOutput', ...
            'The output argument vec is required and must be the same as the second input.\n');
    end
    return;
end

if nargin==1
    vec = zeros(cuVec.dims, 1, 'like', mcuZero(cuVec.type));
end

[vec, errCode] = cuVecCopySubFromGPU(cuVec.dims, cuVec, int32(1), ...
    vec, int32(1), int32(1), varargin{:});
