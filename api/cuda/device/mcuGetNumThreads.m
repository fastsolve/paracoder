function n = mcuGetNumThreads()
% Returns the number of CUDA threads that are currently running.
%
% n = mcuGetNumThreads
%
% Note: This function should only be called from a CUDA kernel function.

if nargin<1; n = int32(1); end
if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
n = cuGridDim_x * cuBlockDim_x;
