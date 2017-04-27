function OMP_clause_schedule(type, chunk) %#codegen
%OMP_clause_schedule  schedule clause for OpenMP
%       OMP_clause_schedule(type [,chunk])
%   type is a charactering, and can be 'static', 'dynamic',
%   'guided', 'runtime', or 'auto' chunk is an integer.
% The function can only be used with OMP_begin_for
%
% Example:
%    OMP_begin_for
%    OMP_clause_schedule('static', n)

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always')
coder.allowpcode('plain')

assert(nargin>=1);
if nargin==1
    coder.ceval('#++ schedule', coder.opaque('const char *', type));
else
    coder.ceval('#++ schedule', coder.opaque('const char *', type), chunk);
end
