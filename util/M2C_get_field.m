function val = M2C_get_field(s, field ) %#codegen
%M2C_get_field Obtain the field of a C struct.
%   val = M2C_get_field(s, field)

coder.inline('always');

val = coder.ceval( 'M2C_GET_FIELD', s, coder.opaque('NOTYPE', field));
end
