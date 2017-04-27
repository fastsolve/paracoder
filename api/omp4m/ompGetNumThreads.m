function n = ompGetNumThreads %#codegen
%ompGetNumThreads  Returns the number of threads that are currently in 
%     the team executing the parallel region from which it is called.

%#codegen -args {}

n = int32(1);
if ~strcmp(coder.target,'rtw'); return; end

momp_require_header
coder.inline('always');
coder.allowpcode('plain')

n = coder.ceval('omp_get_num_threads');
