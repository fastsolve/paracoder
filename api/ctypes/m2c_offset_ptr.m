function ptr = m2c_offset_ptr(ptr, offset) %#codegen
%Offset a pointer by n bytes
%   ptr = M2C_OFFSET_PTR(ptr, n)

coder.inline('always');
if coder.target('rtw')
    coder.cinclude('m2c.h');
end

ptr = coder.ceval('M2C_OFFSET_PTR', ptr, int32(offset));
end
