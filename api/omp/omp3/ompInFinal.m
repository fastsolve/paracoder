function n = ompInFinal %#codegen
%Returns true if the routine is executed in a final task region; otherwise, it returns false.
%
%     n = ompInFinal
%
% This routine is new with OpenMP version 3.0.

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

n = int32(0);

if ~strcmp(coder.target,'rtw'); return; end

n = coder.ceval('omp_in_final');
