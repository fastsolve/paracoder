function n = ompGetAncestorThreadNum(level) %#codegen
%Returns the thread number of the ancestor or the current thread.
%
%     n = ompGetAncestorThreadNum(level)
%
% This routine is new with OpenMP version 3.0.

coder.inline('always');
coder.allowpcode('plain')

coder.cinclude('omp.h');

n = int32(0);

if ~strcmp(coder.target,'rtw'); return; end

n = coder.ceval('omp_get_ancestor_thread_num', level);
