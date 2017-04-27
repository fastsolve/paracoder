function [istart, iend, threadID] = OMP_local_chunk(m, nthreads) %#codegen
% Determines the starting and ending indices of my local chunk
%
% [istart, iend, threadID] = OMP_local_chunk(m) obtains the local chunk
% on the current thread, where m is the number of items within the process.
%
% [istart, iend, threadID] = OMP_local_chunk(m, nthreads) requires that
% only the first n threads perform computation, and the remaining threads
% will remain idle. Note that if nthreads is smaller than the actual number
% of threads, then some chunks may not be taken care of by any thread.
%
% The indices istart and iend are 1-based, and threadID is 0-based.

coder.inline('always');

if nargin<2
    nthreads = ompGetNumThreads;
end

if nthreads==1
    istart = int32(1); iend = int32(m); threadID = int32(0);
else
    threadID = ompGetThreadNum;
    
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
