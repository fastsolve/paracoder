function CU_barrier %#codegen
%CU_barrier  synchronizes all the threads in a block. 
%       CU_barrier 
% When encountered, each thread in the block waits until all of 
% the others have reached this point. After all threads in the block 
% have encountered the barrier, each thread in the block begins 
% executing the statements after the barrier directive in parallel.

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain');

coder.ceval('__syncthreads');
