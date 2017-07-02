function type = m2c_opaque_ptr_type %#codegen
%OPAQUE_PTR_TYPE Create an opaque object for pointer to a given variable.

type = coder.typeof(struct('data', uint64(0), 'type', m2c_string, ...
    'nbytes', int32(0), 'offset', coder.typeof(int32(0))));
