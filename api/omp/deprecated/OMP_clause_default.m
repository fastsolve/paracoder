function OMP_clause_default(type) %#codegen
%OMP_clause_default  set default shared datatype for OpenMP
%       OMP_clause_default(type)
% type is a charactering, and can be 'shared' or 'none'
% The function can be used only with OMP_begin_parallel.
% MOMP uses OMP_clause_default('none') for OMP_begin_parallel by default.
% You can overwrite it by using OMP_clause_default('shared') explictly.

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

coder.ceval('#++ default', coder.opaque('const char *', type));
