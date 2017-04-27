function n = ompGetActiveLevel %#codegen
%Teturns the number of nested, active parallel regions enclosing the task 
%that contains the call.
%
%     n = ompGetActiveLevel
%
% This routine is new with OpenMP version 3.0.

coder.inline('always');
coder.allowpcode('plain')

momp_require_header
n = int32(1);

if ~strcmp(coder.target,'rtw'); return; end

n = coder.ceval('omp_get_active_level');
