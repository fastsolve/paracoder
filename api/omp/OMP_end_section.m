function OMP_end_section %#codegen
%OMP_end_section Marks the end of an OpenMP section.
%
%     OMP_end_section
%
% See also OMP_begin_section, OMP_end_sections

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}section');
