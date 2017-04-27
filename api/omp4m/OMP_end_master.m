function OMP_end_master %#codegen
%OMP_end_master Marks the end of the OpenMP master block.
%
%     OMP_end_master
%
% See also OMP_begin_master

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}master');
