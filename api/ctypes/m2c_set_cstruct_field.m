function m2c_set_cstruct_field(cstruct_ptr, field, val) %#codegen
%m2c_set_cstruct_field sets a field of a C struct by its name to a scalar value.
%   m2c_set_cstruct_field(cstruct_ptr, field, val)

coder.inline('always');
if coder.target('rtw')
    coder.cinclude('m2c.h');
end

coder.ceval('M2C_SET_FIELD', cstruct_ptr, coder.opaque('NOTYPE', field), val);
end
