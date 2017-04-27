function ompSetMaxActiveLevels(levels) %#codegen
%Limits the number of nested active parallel regions.
%
%    ompSetMaxActiveLevels(levels)
%
%  This routine is new with OpenMP version 3.0
%
% See also ompGetMaxActiveLevels

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_set_max_active_levels', levels);
