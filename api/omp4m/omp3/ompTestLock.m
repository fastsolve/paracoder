function ompTestLock(lock) %#codegen
%Attempts to set a lock, but does not block if the lock is unavailable.
%
%    ompTestLock(lock)
%
% Note: This routine is new with OpenMP version 3.0.
%
% See also ompInitNestLock, ompDestroyLock, ompSetLock, ompUnsetLock

coder.inline('always');
coder.allowpcode('plain')

coder.cinclude('omp.h');

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_test_lock', lock);
