function val = m2c_get_cstruct_field(cstruct, field, type, opaque) %#codegen
%m2c_get_cstruct_field obtains a field of a C struct by its name.
%   val = m2c_get_cstruct_field(cstruct, field, type)
% specifies that type is a MATLAB built-in numeric type.
%   val = m2c_get_cstruct_field(cstruct, field, type, opaque)
% specifies that type is an opaque C type string.
%
% See also m2c_set_cstruct_field

coder.inline('always');
if coder.target('rtw')
    coder.cinclude('m2c.h');
end

if nargin<4 || ~opaque
    val = cast(0, type);
    val = coder.ceval('M2C_GET_FIELD', cstruct, coder.opaque('NOTYPE', field));
else
    val = coder.opaque(type);
    val = coder.ceval('M2C_GET_FIELD', cstruct, coder.opaque('NOTYPE', field));
end
end
