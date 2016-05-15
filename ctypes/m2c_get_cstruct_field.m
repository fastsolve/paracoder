function val = m2c_get_cstruct_field(s, field) %#codegen
%m2c_get_cstruct_field Obtain the field of a C struct by its name.
%   val = m2c_get_cstruct_field(cstruct, field)

coder.inline('always');

val = coder.ceval('M2C_GET_FIELD', cstruct, coder.opaque('NOTYPE', field));
end
