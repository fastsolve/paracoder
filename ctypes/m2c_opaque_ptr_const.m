function ptr = m2c_opaque_ptr_const( var, type, offset) %#codegen
%M2C_OPAQUE_PTR_CONST Create an opaque object for read-only pointer to a given variable.
%
% See also m2c_opaque_ptr
%
% The only difference between this function and m2c_opaque_ptr is that it
% does not unshare the objects, so it can lead to better memory efficiency.

coder.inline('always');

if isempty(coder.target)
    dir = fileparts(which('m2c_opaque_ptr_const.m'));
    mex([dir '/m2c_opaque_ptr_const.c'], '-outdir', dir);

    if nargin==0
        ptr = m2c_opaque_ptr_type;
        return;
    else
        error('m2c_opaque_ptr_const:shadow', ['The M function should have been ' ...
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
    
    ptr = castdata( type, var.data);
    
    % Verify parent mxArray still has the same address
    if ~isempty( var.parent) && ~any(var.parent)
        parent = castdata( 'mxArray *', var.parent);
        m2c_chk_opaque_ptr( ptr, parent, var.offset);
    end
elseif isnumeric( var)
    if nargin>1
        ptr = coder.ceval( ['(' type ')'], coder.rref(var));
    else
        ptr = coder.ceval( '(void *)', coder.rref(var));
    end
else
    ptr = var;
end

if nargin==3 && offset~=0
    ptr = m2c_offset_ptr( ptr, int32(offset));
end
end

function ptr = m2c_offset_ptr(ptr, n) %#codegen
%Offset a pointer by n bytes
%   ptr = M2C_OFFSET_PTR(ptr, n)

coder.inline('always');

ptr = coder.ceval('M2C_OFFSET_PTR', ptr, int32(n));
end
