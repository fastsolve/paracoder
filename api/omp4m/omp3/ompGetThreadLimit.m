function n = ompGetThreadLimit %#codegen
%ompGetThreadLimit  Returns the maximum number of OpenMP threads available to a program.
%
% This function is new with OpenMP 3.0.

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

n = int32(1);

if ~strcmp(coder.target,'rtw'); return; end

n = coder.ceval('omp_get_thread_limit');
