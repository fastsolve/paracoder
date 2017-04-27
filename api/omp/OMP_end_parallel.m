function OMP_end_parallel %#codegen
%OMP_end_parallel Marks the end of the OpenMP parallel section.
%
%     OMP_end_parallel
%
% This directive should be paired with OMP_begin_parallel.
% An implied barrier exists at this statement.
%
% See also OMP_begin_parallel

if ~strcmp(coder.target,'rtw'); return; end

coder.inline('always');
coder.allowpcode('plain')

coder.ceval('#}parallel');
