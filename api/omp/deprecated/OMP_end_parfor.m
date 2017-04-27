function OMP_end_parfor %#codegen
%OMP_end_parfor Marks the end of the OpenMP "parallel for" block.
%
%     OMP_end_parfor
%
% An implied barrier exists at the end of a parfor statement block.
% This directive should be paired with OMP_begin_parfor.
%
% See also OMP_begin_parfor

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}parfor');
