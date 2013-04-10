function ptr = opaque_ptr( var, type, offset) %#codegen
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
% When called in code generation, it creates an opaque "void *" pointer
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

coder.extrinsic('warning');

if isempty(coder.target)
    dir = which('opaque_ptr.m'); dir = dir(1:end-12);
    mex([dir 'src/opaque_ptr.c']);
    
    if nargin==0
        ptr = opaque_ptr_type;
        return;
    else
        error('opaque_ptr:shadow', ['The M function should have been ' ...
            'shadowed by the mex file, which was missing. I have rebuilt the mex file.' ...
            'Please try to rerun your last function again.']);
    end
end

if nargin<2; type = 'void *'; end
ptr = coder.opaque( type);
if isstruct( var)
    assert( isfield( var, 'data') && isfield( var, 'type') && isfield( var, 'nbytes') ...
        && isfield( var, 'parent') && isfield( var, 'offset') && ...
        ischar(var.type) && size(var.data,2)==1 && var.nbytes>=1);

    ptr = getptr( type, var.data);
    
    % Verify parent mxArray still has the same address
    if ~isempty( var.parent) && ~any(var.parent)
        parent = getptr( 'mxArray *', var.parent);
        M2C_chk_opaque_ptr( ptr, parent, var.offset);
        if length(var.type)>6 && isequal(var.type(1:6),'const ')
            warning('opaque_ptr:ConstPtr', 'Discarding the const modifier of an opaque_ptr.');
        end
    end
elseif isnumeric( var)
    if nargin>1
        ptr = coder.ceval( ['(' type ')'], coder.rref(var));
    else
        ptr = coder.ceval( ' ', coder.rref(var));
    end
else
    ptr = var;
end

if nargin==3 && offset~=0
    ptr = M2C_offset_ptr( ptr, int32(offset));
end

function ptr = getptr(type, data)
ptr = coder.opaque( type);
ptr = coder.ceval( ['*(' type '*)'], coder.rref(data));