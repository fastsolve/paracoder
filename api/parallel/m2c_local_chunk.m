function [istart, iend, threadID] = m2c_local_chunk(m, varargin)
% Determines the starting and ending indices of the local chunk.
%
% [istart, iend, threadID] = m2c_local_chunk(m) obtains the local chunk
% on the current thread. When generating serial code, istart=1, iend=m,
% and threadID=0. When generating OpenMP or CUDA code, it returns the
% local chunk assigned to the current thread, and optionally the
% corresponding threadID. Note that all the indices istart and iend
% are 1-based, but the threadID is 0-based (for consistency with the
% convention of OpenMP and CUDA).
%
% [istart, iend, threadID] = m2c_local_chunk(m, nthreads) assumes the
% number of threads equals nthreads, instead of trying to determine it
% by calling the OpenMP or CUDA runtime system.

coder.inline('always');

narginchk(1,2);
nargoutchk(2,3)

istart = int32(1); iend = int32(m); threadID = int32(0);
