function flag = m2c_debug
%Flag indicating whether m2c_debug is on.
%It is always true within MATLAB. In the generated C code, it is
%turned off by the -DNDEBUG compiler option. It can also be turned on 
%or off by the compiler options -DM2C_DEBUG=1  DM2C_DEBUG=0, respectively.

coder.inline('always');

if isempty(coder.target)
    flag = true;
else 
    flag = int32(1); %#ok<NASGU>
    flag = coder.ceval(' ', coder.opaque('int', 'M2C_DEBUG'));
end
end
