function OMP_clause_nowait %#codegen
%OMP_clause_nowait   nowait clause for OpenMP
%   OMP_clause_nowait
%
% This directive must be used following OMP_begin_section or OMP_begin_single.
%
% Example:
%    OMP_begin_section
%    OMP_clause_schedule('static', n)
%    OMP_clause_nowait
%
%    ... function calls
%
%    OMP_end_section

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

coder.ceval('#++ nowait');
