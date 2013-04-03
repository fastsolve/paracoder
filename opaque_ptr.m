%OPAQUE_PTR Create an opaque object for pointer to a given variable.
% The function behaves differently within MATLAB and in code generation
%
% In MATLAB, it creates a pointer object, which is a struct with five fields:
%         data:   pointer stored as an uint8 array 
%         type:   pointer type stored as a character string
%         nbytes: number of bytes of the parent object
%         parent: a reference back to the parent mxArray
%         offset: offset of data pointer from data pointer in parent object
% There are two cases:
%    ptrobj = opaque_ptr( var, [type], [offset]) creates a pointer object
%    to the data in a numeric array. It also stores a reference back
%    to the mxArray struct of the numeric array.
%
%    ptrobj = opaque_ptr( ptrobj, [type], [offset]) copies the pointer object,
%    and checks to make sure the parent mxArray struct is still valid
%    (if ptrobj.parent field is not empty and is not a null pointer.)
%
% When called in code generation, it creates an opaque "char *" pointer
%    or the type specified by the second variable. There are three cases:
%
%    ptr = opaque_ptr( var, [type], [offset]) creates an opaque pointer 
%    to the data in a numeric array. 
%
%    ptr = opaque_ptr( ptrobj, [type], [offset]) copies the address stored 
%    in the pointer object into the opaque pointer. It also checks
%    to make sure the parent mxArray struct is still valid
%    (if ptrobj.parent field is not empty and is not a null pointer.)
%
%    ptr = opaque_ptr( ptr, [type], [offset]) copies the opaque pointer.
%
% In all the above cases, if offset (int32) is specified, then the pointer 
% is shifted by offset bytes.
%
% If the function is called without any argument, then it calls
% opaque_ptr_type to obtain a type description to be used by codegen.
%
% See also opaque_obj
