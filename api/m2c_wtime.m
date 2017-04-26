function t = m2c_wtime
% Return ellapsed time
%   t = m2c_wtime

%#codegen -args {}
coder.extrinsic('etime','clock');
if isempty(coder.target)
    % [year month day hour minute seconds]
    t = etime(clock, [1970,1,1,0,0,0]);
elseif coder.target('mex')
    t = etime(clock, [1970,1,1,0,0,0]);
elseif ~m2c_par_target('gpu')
    coder.inline('always');
    coder.cinclude('m2c.h');
    
    t = 0;  %#ok<NASGU>
    t = coder.ceval('M2C_wtime');
else
    % No support for timing for GPU device code
    t = 0;
end
