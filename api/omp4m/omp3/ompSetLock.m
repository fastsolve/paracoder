function ompSetLock(lock) %#codegen
%Forces the executing thread to wait until the specified lock 
% is available. A thread is granted ownership of a lock when it becomes available.
%
%    ompSetLock(lock)
%
% Note: This routine is new with OpenMP version 3.0.
%
% See also ompInitNestLock, ompDestroyLock, ompSetLock, ompUnsetLock, ompTestLock

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_set_lock', lock);
