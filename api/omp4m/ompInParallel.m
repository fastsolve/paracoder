function n = ompInParallel %#codegen
%Determines if the current section of code is parallel or not.

n = int32(0);
if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

n = coder.ceval('omp_in_parallel');
