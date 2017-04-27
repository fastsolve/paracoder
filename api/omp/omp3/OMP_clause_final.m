function OMP_clause_final(expr) %#codegen
%OMP_clause_final  final clause for OpenMP
%   OMP_clause_final(expr)
%
% It should be used after OMP_begin_task.
%
% Example: OMP_clause_final(expr)
%
% Note: It is new in OpenMP 3.0.

coder.inline('always')
coder.allowpcode('plain')

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('#++ final', coder.rref(expr));
