function OMP_end_sections %#codegen
%OMP_end_sections Marks the end of OpenMP sections.
%
%     OMP_end_sections
%
% See also OMP_begin_sections, OMP_end_section

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}sections');
