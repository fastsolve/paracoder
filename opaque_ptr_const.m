function ptr = opaque_ptr_const( var, type, offset) %#codegen
%OPAQUE_PTR_CONST Create an opaque object for read-only pointer to a given variable.
%
% See also opaque_ptr
%
% The only difference between this function and opaque_ptr is that it
% does not unshare the objects, so it can lead to better memory efficiency.

coder.inline('always')

if isempty(coder.target)
    dir = which('opaque_ptr.m'); dir = dir(1:end-12);
    mex(['-I' dir], [dir 'src/opaque_ptr_const.c']);
    
    if nargin==0
        ptr = opaque_ptr_type;
        return;
    else
        error('opaque_ptr_const:shadow', ['The M function should have been ' ...
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
