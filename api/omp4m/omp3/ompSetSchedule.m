function ompSetSchedule(kind, modifier) %#codegen
%Sets the schedule type that is applied when the loop 
%  directive specifies a runtime schedule.
%
%    ompSetSchedule(schedule, modifier)
%
% Note: This routine is new with OpenMP version 3.0.
%
% See also ompGetSchedule

coder.inline('always');
coder.allowpcode('plain')

coder.cinclude('omp.h');

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_set_schedule', kind, modifier);
