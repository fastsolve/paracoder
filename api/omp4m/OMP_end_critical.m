function OMP_end_critical %#codegen
%OMP_end_critical Marks the end of the OpenMP critical section.
%
%     OMP_end_critical
% 
% See also OMP_begin_critical

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}critical');
