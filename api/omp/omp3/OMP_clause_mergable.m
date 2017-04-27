function OMP_clause_mergable %#codegen
%OMP_clause_mergable   mergable clause for OpenMP
%   OMP_clause_mergable
%
% This directive must be used after OMP_end_task.
%
% Example:
%    OMP_begin_task
%    OMP_clause_schedule('static', n)
%    OMP_clause_mergable
%    statements...
%    OMP_end_task
%
% Note: It is new in OpenMP 3.0.

coder.inline('always')
coder.allowpcode('plain')

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('#++ mergable');
