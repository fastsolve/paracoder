function ompDestroyNestLock(lock) %#codegen
%Disassociates the given lock variable from any locks.
%
%    ompDestroyNestLock(lock)
%
% Note: This routine is new with OpenMP version 3.0.
%
% See also ompDestroyLock, ompInitNestLock, ompSetNestLock, ompUnsetNestLock, ompTestNestLock

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_destroy_nest_lock', lock);
