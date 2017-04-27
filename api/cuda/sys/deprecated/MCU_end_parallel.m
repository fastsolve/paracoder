function MCU_end_parallel
%Marks the end of a CUDA parallel section.
%
%     MCU_end_parallel
%
% This directive should be paired with MCU_begin_parallel.
% An implied barrier exists at this statement.
%
% See also MCU_begin_parallel

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}cuda');
