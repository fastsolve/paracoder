function type = opaque_obj_type %#codegen
%OPAQUE_OBJ_TYPE Create an opaque object for pointer to a given variable.

type = coder.typeof(struct('data',coder.typeof(uint8(0),[inf,inf]), ...
    'type',coder.typeof('0',[1,inf]), 'nitems', int32(0)));
