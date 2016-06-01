function flag = m2c_debug
%Flag indicating whether m2c_debug is on.
%It is always true within MATLAB. In the generated C code, it is
%turned off by the -DNDEBUG compiler option. It can also be turned on
%or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively.

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
