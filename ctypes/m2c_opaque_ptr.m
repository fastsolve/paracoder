function ptr = m2c_opaque_ptr(var, type, offset) %#codegen
%M2C_OPAQUE_PTR Create an opaque object for pointer to a given variable.
% The function behaves differently within MATLAB and in code generation
%
% In MATLAB, it creates a pointer object, which is a struct with five fields:
%         data:   pointer stored as an uint8 array 
%         type:   pointer type stored as a character string
%         nbytes: number of bytes of the parent object
%         parent: a reference back to the parent mxArray
%         offset: offset (in bytes) of pointer from data pointer in parent object
% There are two cases:
%    ptrobj = m2c_opaque_ptr(var, [type], [offset]) creates a pointer object
%    to the data in a numeric array. It also stores a reference back
%    to the mxArray struct of the numeric array.
%
%    ptrobj = m2c_opaque_ptr(ptrobj, [type], [offset]) copies the pointer object,
%    and checks to make sure the parent mxArray struct is still valid
%    (if ptrobj.parent field is not empty and is not a null pointer.)
%
% When called in code generation, it creates an opaque "void *" pointer
%    or the type specified by the second variable. There are three cases:
%
%    ptr = m2c_opaque_ptr(var, [type], [offset]) creates an opaque pointer 
%    to the data in a numeric array. 
%
%    ptr = m2c_opaque_ptr(ptrobj, [type], [offset]) copies the address stored 
%    in the pointer object into the opaque pointer. It also checks
%    to make sure the parent mxArray struct is still valid
%    (if ptrobj.parent field is not empty and is not a null pointer.)
%
%    ptr = m2c_opaque_ptr(ptr, [type], [offset]) copies the opaque pointer.
%
% In all the above cases, if offset (int32) is specified, then the pointer 
% is shifted by offset bytes.
%
% If the function is called without any argument, then it calls
% m2c_opaque_ptr_type to obtain a type description to be used by codegen.
%
% See also m2c_opaque_obj

if isempty(coder.target)
    dir = fileparts(which('m2c_opaque_ptr.m'));
    mex([dir '/m2c_opaque_ptr.c'], '-outdir', dir);
    
    if nargin==0
        ptr = m2c_opaque_ptr_type;
        return;
    else
        error('m2c_opaque_ptr:shadow', ['The M function should have been ' ...
            'shadowed by the mex file, which was missing. I have rebuilt the mex file.' ...
            'Please try to rerun your last function again.']);
    end
end

if nargin<2; type = 'void *'; end
ptr = coder.opaque(type);
if isstruct(var)
    assert(isfield(var, 'data') && isfield(var, 'type') && isfield(var, 'nbytes') ...
        && isfield(var, 'parent') && isfield(var, 'offset') && ...
        ischar(var.type) && size(var.data,2)==1 && var.nbytes>=1);

    ptr = castdata(type, var.data);
    
    % Verify parent mxArray still has the same address
    if ~isempty(var.parent) && ~any(var.parent)
        parent = castdata('mxArray *', var.parent);
        m2c_chk_opaque_ptr(ptr, parent, var.offset);
        if length(var.type)>6 && isequal(var.type(1:6),'const ')
            m2c_warn('m2c_opaque_ptr:ConstPtr', 'Discarding the const modifier of an m2c_opaque_ptr.');
        end
    end
elseif isnumeric(var)
    if nargin>1
        ptr = coder.ceval(['(' type ')'], coder.rref(var));
    else
        ptr = coder.ceval('(void *)', coder.rref(var));
    end
else
    ptr = var;
end

if nargin==3 && offset~=0
    ptr = m2c_offset_ptr(ptr, int32(offset));
end
end

function ptr = m2c_offset_ptr(ptr, n) %#codegen
%Offset a pointer by n bytes
%   ptr = M2C_OFFSET_PTR(ptr, offset)

coder.inline('always');

ptr = coder.ceval('M2C_OFFSET_PTR', ptr, int32(n));
end
