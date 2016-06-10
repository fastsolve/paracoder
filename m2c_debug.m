function flag = m2c_debug
%Flag indicating whether m2c_debug is on.
%It is always true within MATLAB. During code generation, it is on
%if -g is explicitly or implicitly specified.

coder.inline('always');
coder.cinclude('m2c.h');

flag = true;

if isempty(coder.target)
    return;
end

if coder.target('rtw')
    coder.cinclude('m2c.h');
end
flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG'));
