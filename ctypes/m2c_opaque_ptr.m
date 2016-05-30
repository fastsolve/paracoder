function ptr = m2c_opaque_ptr(var, type, offset, varargin) %#codegen
% Creates a pointer to the given variable, to be passed to a C function.
%
% m2c_opaque_ptr() simply returns m2c_opaque_ptr_type, which is suitable
% for using in argument specification for codegen.
%
% m2c_opaque_ptr(var, [type], [offset]) takes a primitive MATLAB varilable
% or an opaque C data type and creates a pointer of the given data type,
% shifted by offset elements. The argument type is a constant string
% stroing a C pointer type, such as 'double *'. The argument offset is int32,
% indicating that the given number of elements (e.g., double) to be shifted.
%
% Note that since type must be a constant string at compile time, if it is
% not given, then 'char *' will be assumed, so that the offset will be in
% bytes. If offset is omitted, then 0 offset is assumed.
%
% When called in MATLAB, the output is a struct of type m2c_opaque_ptr_type.
% In this case, type must be 'char *' or 'const char *' if the offset is
% nonzero. You can retrieve the pointer using m2c_opaque_ptr_type(ptr)
% with the preset offset, or using m2c_opaque_ptr_type(ptr, type, offset)
% with a new type or offset.
%
% m2c_opaque_ptr(ptr, [type], [offset]) takes a pointer (or m2c_opaque_ptr_type
% in MATLAB) and maps it into a new pointer with the new type and offset.
%
% Note: Unlike m2c_opaque_obj, this function cannot be used to return an
% opaque C object to MATLAB. Use m2c_opaque_obj to wrap a C pointer and
% then use m2c_opaque_obj2ptr to convert the object into a pointer.
%
% See also m2c_opaque_obj, m2c_opaque_array, m2c_opaque_ptr_const

if isempty(coder.target)
    dir = fileparts(which('m2c_opaque_ptr.m'));
    if exist('octave_config_info', 'builtin')
        mex([dir '/m2c_opaque_ptr.c'], '-o', ...
            [dir '/m2c_opaque_ptr.' mexext]);
    else
        mex([dir '/m2c_opaque_ptr.c'], '-outdir', dir);
    end
    
    if nargin==0
        ptr = m2c_opaque_ptr_type;
        return;
    else
        error('m2c_opaque_ptr:shadow', ['The M function should have been ' ...
            'shadowed by the mex file, which was missing. I have rebuilt the mex file.' ...
            'Please try to rerun your last function again.']);
    end
end

if nargin<2; type = 'char *'; end

ptr = coder.opaque(type);
if isstruct(var) && isfield(var, 'offset')
    ptr = castdata(type, var.data);
    
    if (nargin<4 || ~varargin{1}) && length(var.type)>6 && isequal(var.type(1:6),'const ')
        m2c_warn('m2c_opaque_ptr:ConstPtr', 'Discarding the const modifier of an m2c_opaque_ptr.');
    end
elseif isnumeric( var)
    if nargin>1
        ptr = coder.ceval( ['(' type ')'], coder.rref(var));
    else
        ptr = coder.ceval( '(char *)', coder.rref(var));
    end
else
    ptr = var;
end

if nargin>=3 && offset~=0
    ptr = m2c_offset_ptr(ptr, int32(offset));
elseif isstruct(var) && isfield(var, 'offset') && var.offset~=0
    if m2c_debug && nargin>1
        m2c_error('m2c_opaque_ptr:Incorrect type', ...
            'When using prestored offset, you cannot specify type again.\n');
    end
    ptr = m2c_offset_ptr(ptr, int32(var.offset));
end
end

function ptr = m2c_offset_ptr(ptr, n) %#codegen
%Offset a pointer by n bytes
%   ptr = M2C_OFFSET_PTR(ptr, offset)

coder.inline('always');
ptr = coder.ceval('M2C_OFFSET_PTR', ptr, int32(n));
end
