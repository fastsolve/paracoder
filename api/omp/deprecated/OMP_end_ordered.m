function OMP_end_ordered %#codegen
%OMP_end_ordered Marks the end of the OpenMP an ordered block.
% 
%     OMP_end_ordered
%
% See also OMP_begin_ordered

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}ordered');
