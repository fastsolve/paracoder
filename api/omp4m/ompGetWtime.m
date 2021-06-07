function time = ompGetWtime
%Provides a portable wall clock timing routine.
%
%    time = ompGetWtime
% 
% Returns a double-precision floating point value equal to the number of 
% elapsed seconds since some point in the past. Usually used in "pairs" 
% with the value of the first call subtracted from the value of the second 
% call to obtain the elapsed time for a block of code.
% Designed to be "per thread" times, and therefore may not be globally 
% consistent across all threads in a team - depends upon what a thread 
% is doing compared to other threads.
%
% See also ompGetWtick

%#codegen -args {}

if ~strcmp(coder.target,'rtw'); 
    time = m2c_wtime;
    return; 
end

coder.cinclude('omp.h');
coder.inline('always');
coder.allowpcode('plain')

time = 0; %#ok<NASGU>
time = coder.ceval('omp_get_wtime');
