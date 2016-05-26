function val = m2c_get_cstruct_field(cstruct, field, type) %#codegen
%m2c_get_cstruct_field obtains a field of a C struct by its name.
%   val = m2c_get_cstruct_field(cstruct, field, type)
%where type a MATLAB basic data type.

coder.inline('always');

val = cast(0, type);
val = coder.ceval('M2C_GET_FIELD', cstruct, coder.opaque('NOTYPE', field));
end
