function ompSetNumThreads(num_threads) %#codegen
%Sets the number of threads that will be used in the next parallel region.
%Must be a postive integer.
%    ompSetNumThreads(num_threads)
% See also ompGetNumThreads

%#codegen -args {int32(0)}

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

coder.ceval('omp_set_num_threads', num_threads);
