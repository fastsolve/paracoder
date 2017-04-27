function n = ompGetThreadNum %#codegen
%Returns the thread number of the thread, within the team, making this call. 
% This number will be between 0 and OMP_GET_NUM_THREADS-1. 
% The master thread of the team is thread 0

%#codegen -args {}

n = int32(0);
if ~strcmp(coder.target,'rtw'); return; end

momp_require_header
coder.inline('always');
coder.allowpcode('plain')

n = coder.ceval('omp_get_thread_num');
