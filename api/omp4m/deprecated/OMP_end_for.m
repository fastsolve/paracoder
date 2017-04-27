function OMP_end_for %#codegen
%OMP_end_for Marks the end of the OpenMP for block.
%
%     OMP_end_for
%
% See also OMP_begin_for

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}for');
