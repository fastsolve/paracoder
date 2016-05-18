function m2c_chk_opaque_ptr(ptr, parent, offset) %#codegen
%M2C_CHK_OPAQUE_PTR  Check opaque pointer
%   m2c_chk_opaque_ptr(ptr, parent, offset)

coder.cinclude('matrix.h');

coder.inline('always');
coder.ceval('M2C_CHK_OPAQUE_PTR', ptr, parent, offset);
