function OMP_clause_untied %#codegen
%OMP_clause_untied   untied clause for OpenMP
%   OMP_clause_untied
%
% This directive must be used after OMP_begin_task
%
% Example:
%    OMP_begin_task
%    OMP_clause_schedule('static', n)
%    OMP_clause_untied
%      statements...
%    OMP_end_task
%
% Note: It is new in OpenMP 3.0.

coder.inline('always')
coder.allowpcode('plain')

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('#++ untied');
