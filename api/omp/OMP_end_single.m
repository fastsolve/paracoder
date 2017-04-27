function OMP_end_single %#codegen
%OMP_end_single Marks the end of the OpenMP serial block.
%
%     OMP_end_single
%
% See also OMP_begin_single

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}single');
