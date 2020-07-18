function type = m2c_opaque_type %#codegen
%M2C_OPAQUE_TYPE Opaque object type for pointer to a given variable.

type = coder.cstructname(struct('data',coder.typeof(uint8(0),[inf,1]), ...
    'type',coder.typeof('0',[1,inf]), 'nitems', int32(0)), 'M2C_OpaqueType');
