function n = cuGetThreadNum
%Returns the thread number of the current CUDA thread.
% This number will be between 0 and cuGetNumThreads-1.
%
% Note: This function can only be called from a CUDA kernel function.

n = int32(0);
if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
n = cuBlockIdx_x * cuBlockDim_x + cuThreadIdx_x;
