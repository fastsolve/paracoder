function ompSetNested(nested) %#codegen
%Enables or disables nested parallelism.
%
%    ompSetNested(nested)
%
% See also ompGetNested

%#codegen -args {int32(0)}

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.cinclude('omp.h');

coder.ceval('omp_set_nested', nested);
