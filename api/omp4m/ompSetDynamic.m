function ompSetDynamic(dynamic) %#codegen
%ompSetDynamic  enables or disables dynamic adjustment (by the run time system)
%  of the number of threads available for execution of parallel regions.
%
%    ompSetDynamic(dynamic)
%
% See also ompGetDynamic

%#codegen -args {int32(0)}

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.cinclude('omp.h');

coder.ceval('omp_set_dynamic', dynamic);
