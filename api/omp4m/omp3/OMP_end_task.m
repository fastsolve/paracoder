function OMP_end_task %#codegen
%OMP_end_task Marks the end of an OpenMP task.
%
%     OMP_end_task
%
% See also OMP_begin_task

coder.inline('always');
coder.allowpcode('plain')

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('#}task');
