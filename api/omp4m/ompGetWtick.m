function tick = ompGetWtick
%Returns a double-precision floating point value equal 
%   to the number of seconds between successive clock ticks.
%
%    tick = ompGetWtick
% 
% See also ompGetWtime

%#codegen -args {}

tick = 0;
if ~strcmp(coder.target,'rtw'); return; end

coder.cinclude('omp.h');
coder.inline('always');
coder.allowpcode('plain')

tick = coder.ceval('omp_get_wtick');
