function n = ompGetMaxThreads 
%ompGetMaxThreads Returns the maximum value that can be returned by a call to the ompGetNumThreads function.
%   n = ompGetMaxThreads
% See also ompGetThreadLimit

%#codegen -args {}

n = int32(1);
if ~strcmp(coder.target,'rtw'); return; end

coder.cinclude('omp.h');
coder.inline('always');
coder.allowpcode('plain')

n = coder.ceval('omp_get_max_threads');
