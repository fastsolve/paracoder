function ompInitNestLock(lock) %#codegen
%Initializes a lock associated with the lock variable.
%
%    ompInitNestLock(lock)
%
% Note: This routine is new with OpenMP version 3.0.
%
% See also ompInitLock, ompDestroyNestLock, ompSetNestLock, ompUnsetNestLock, ompTestNestLock

coder.inline('always');
coder.allowpcode('plain')

coder.cinclude('omp.h');

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_init_nest_lock', lock);
