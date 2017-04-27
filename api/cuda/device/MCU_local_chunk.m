function [istart, iend, threadID] = MCU_local_chunk(m, nthreads)
% Determines starting and ending indices of local chunk on a CUDA thread.
%
% [istart, iend, threadID] = MCU_local_chunk(m) obtains the local chunk on
% each CUDA thread, where m is the total number of items.
%
% [istart, iend, threadID] = MCU_local_chunk(m, nthreads) requires only
% the first n threads perform computation, and the remaining threads remain
% idle. Note that if nthreads is smaller than the actual number of threads,
% then some chunks may not be taken care of by any thread.
%
% By convention, this function should be called by a CUDA global function.
% The indices istart and iend are 1-based, and threadID is 0-based.

coder.inline('always');

if nargin<2
    nthreads = mcuGetNumThreads;
end

if nthreads==1
    istart = int32(1); iend = int32(m); threadID = int32(0);
else
    threadID =  mcuGetThreadNum;
    
    if nargin>1 && threadID>=nthreads
        % The excess threads would not be assigned any task
        istart = int32(1); iend = int32(0);
    else
        chunk = m2c_intdiv(m, nthreads);
        remainder = m-nthreads*chunk;
        
        istart = threadID*chunk+min(remainder,threadID)+1;
        iend = istart+chunk+int32(threadID<remainder)-1;
    end
end
