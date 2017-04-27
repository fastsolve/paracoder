function n = ompGetTeamSize(level) %#codegen
%Returns, for a given nested level of the current thread, the size of the 
% thread team to which the ancestor or the current thread belongs.
%     n = ompGetTeamSize(level)
%
% This routine is new with OpenMP version 3.0.

coder.inline('always');
coder.allowpcode('plain')

momp_require_header

n = int32(1);

if ~strcmp(coder.target,'rtw'); return; end

n = coder.ceval('omp_get_team_size', level);
