function t = m2c_wtime
% Return ellapsed time
%   t = m2c_wtime

%#codegen -args {}

if isempty(coder.target)
    % [year month day hour minute seconds]
    t = etime(clock, [1970,1,1,0,0,0]);
elseif coder.target('mex')
    coder.extrinsic('etime', 'clock');
    t = etime(clock, [1970,1,1,0,0,0]);
else
    coder.inline('always');
    
    t = 0;  %#ok<NASGU>
    t = coder.ceval('M2C_wtime');
end
