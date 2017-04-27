function n = ompGetLevel %#codegen
%Returns the number of nested parallel regions enclosing the task that contains the call.
%     n = ompGetLevel
%
% This routine is new with OpenMP version 3.0.

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

n = int32(1);

if ~strcmp(coder.target,'rtw'); return; end

n = coder.ceval('omp_get_level');
