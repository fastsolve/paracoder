function OMP_clause_if(cond) %#codegen
%OMP_clause_if  if clause for OpenMP
%   OMP_clause_if(cond)
%
% Example: OMP_clause_if(cond)

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

coder.ceval('#++ if', coder.rref(cond));
