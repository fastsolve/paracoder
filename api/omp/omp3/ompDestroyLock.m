function ompDestroyLock(lock) %#codegen
%Disassociates the given lock variable from any locks.
%
%    ompDestroyLock(lock)
%
% Note: This routine is new with OpenMP version 3.0.
%
% See also ompDestroyNestLock, ompInitLock, ompSetLock, ompUnsetLock, ompTestLock

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_destroy_lock', lock);
