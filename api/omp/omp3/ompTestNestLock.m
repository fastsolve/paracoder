function ompTestNestLock(lock) %#codegen
%Attempts to set a lock, but does not block if the lock is unavailable.
%
%    ompTestNestLock(lock)
%
% Note: This routine is new with OpenMP version 3.0.
%
% See also ompInitLock, ompDestroyNestLock, ompSetNestLock, ompUnsetNestLock

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_test_nest_lock', lock);
