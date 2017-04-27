function ompInitLock(lock) %#codegen
%Initializes a lock associated with the lock variable.
%
%    ompInitLock(lock)
%
% Note: This routine is new with OpenMP version 3.0.
%
% See also ompInitNestLock, ompDestroyLock, ompSetLock, ompUnsetLock, ompTestLock

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_init_lock', lock);
