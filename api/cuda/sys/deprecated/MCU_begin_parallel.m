function MCU_begin_parallel(nthreads, threadsPB, device)
%Indicates that the following function calls will be executed on a
%particular CUDA device.
%
% Syntax:
%       MCU_begin_parallel()
%       MCU_begin_parallel(nthreads)
%       MCU_begin_parallel(nthreads, threadsPB)
%       MCU_begin_parallel(nthreads, device)
%
% Description:
% MCU_begin_parallel() requests MCUDA to decide the maximum number of
% threads automatically based on the GPU card on the system.
%
% MCU_begin_parallel(nthreads) requests MCUDA to use the given number of
% threads, but decide the number of blocks and the number of threads per
% block automatically based on the GPU card on the system. Set nthreads
% to <=0 to request MCUDA to determine the number of threads automatically.
%
% MCU_begin_parallel(nthreads, threadsPB) requests MCUDA to use the given
% number of threads and the number of threads per blocks on the current
% CUDA device. Set nthreads or threadsPB to <=0 to request MCUDA to select
% them automatically.
%
% MCU_begin_parallel(nthreads, threadsPB, device) requests MCUDA to use
% the specified CUDA device. If device<0, then use the current device.
%
% Note: This function must be paired with MCU_end_parallel. If the device is
% specified, there is an implicit OpenMP critical section between 
% MCU_begin_parallel and MCU_end_parallel.
%
% The functions between MCU_begin_parallel and MCU_end_parallel must be
% CUDA kernel functions. For a MATLAB function to qualify as a CUDA kernel
% function for code generation, it must satisfy the following requirements:
%  - It can only take numeric arrays as input. No struct is allowed.
%  - It must not have any dynamic memory allocation in it.
%  - All the size information of the arrays must be passed in as input
%    arguments instead of obtained using the size() function.
%  - It can only call other kernel functions.
%
% See also: MCU_end_parallel

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
if nargin<=1 || threadsPB<=0
    [maxthreads, threadsPB] = mcuGetMaxThreads;
    if nargin==0 || nthreads<=0
        nthreads = maxthreads;
    end
end

nB = m2c_intdiv(nthreads-1, threadsPB) + 1;
if nargin>2 && device>=0
    [~] = cuSetDevice(device);
end

coder.ceval('#{cuda', coder.opaque('NOTYPE', 'async'));
coder.ceval('#pragma mcuda set_threads', nB, threadsPB);
