function OMP_clause_ordered %#codegen
%OMP_clause_ordered   ordered clause for OpenMP
%   OMP_clause_ordered
%
% This directive must be used after OMP_begin_for and OMP_begin_parfor.

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

coder.ceval('#++ ordered');
