function [istart, iend, threadID] = m2c_local_chunk(m, nthreads, mode)
% Determines starting and ending indices of local chunk on a CUDA thread.
%
% [istart, iend, threadID] = m2c_local_chunk(m, nthreads, [mode])
% obtains the local chunk on each thread of a particular mode, where
% mode is 'omp' or 'cuda', and m is the total number of items. The mode
% must evaluate to a a constant string at compile time.
% If nthreads is a constant 1, then mode can be omitted.
%
% It is a simple wrapper function for OMP_local_chunk and MCU_local_chunk,
% for unified programming.

coder.inline('always');

if nthreads==1
    istart = int32(1); iend = int32(m); threadID = int32(0);
elseif isequal(mode, 'omp')
    [istart, iend, threadID] = OMP_local_chunk(m, nthreads, mode);
elseif isequal(mode, 'cuda')
    [istart, iend, threadID] = MCU_local_chunk(m, nthreads, mode);
else
    m2c_error('m2c_local_chunk:UnknownMode', ...
        'You must specify a valid mode if nthreads is not 1.\n');
end
