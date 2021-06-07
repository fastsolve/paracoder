function n = ompGetDynamic %#codegen
%ompGetDynamic  determines whether dynamic thread adjustment is enabled or not.

%#codegen -args {}

n = int32(0);
if ~strcmp(coder.target,'rtw'); return; end

coder.cinclude('omp.h');
coder.inline('always');
coder.allowpcode('plain')

n = coder.ceval('omp_get_dynamic');
