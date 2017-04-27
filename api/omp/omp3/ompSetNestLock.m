function ompSetNestLock(nest_lock) %#codegen
%Forces the executing thread to wait until the specified nest_lock 
% is available. A thread is granted ownership of a nest_lock when it becomes available.
%
%    ompSetNestLock(nest_lock)
%
% Note: This routine is new with OpenMP version 3.0.
%
% See also ompInitLock, ompDestroyNestLock, ompSetNestLock, ompUnsetNestLock, ompTestNestLock

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_set_nest_lock', nest_lock);
