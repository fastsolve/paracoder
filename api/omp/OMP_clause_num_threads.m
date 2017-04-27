function OMP_clause_num_threads(n) %#codegen
%OMP_clause_num_threads  num_threads clause for OpenMP
%   OMP_clause_num_threads(n)
%
% Example: OMP_clause_num_threads(n)

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

coder.ceval('#++ num_threads', n);
