function [kind, modifier] = ompGetSchedule %#codegen
%ompGetSchedule  returns the schedule that is applied when the loop 
%   directive specifies a runtime schedule.
% 
% This routine is new with OpenMP version 3.0

coder.inline('always');
coder.allowpcode('plain')

coder.cinclude('omp.h');

kind = coder.opaque('omp_sched_t');
modifier = int32(0);

if ~strcmp(coder.target,'rtw'); return; end

coder.ceval('omp_get_schedule', coder.ref(kind), coder.wref(modifier));
