function OMP_clause_collapse(n) %#codegen
%OMP_clause_collapse  collapse clause for OpenMP
%   OMP_clause_collapse(n)
%
% This clause can be used with the OMP_begin_for.
%
% Example:
%    OMP_begin_for
%    OMP_clause_schedule('static', n)
%    OMP_clause_collapse (n)
%
%    ... for loop
%
%    OMP_end_for

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

coder.ceval('#++ collapse', coder.rref(n));
