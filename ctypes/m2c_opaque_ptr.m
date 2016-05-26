function ptr = m2c_opaque_ptr(var, type, offset, varargin) %#codegen
% Creates a pointer to the given variable, to be passed to a C function.
% The function behaves differently within MATLAB and in C.
%
% m2c_opaque_ptr() simply returns m2c_opaque_ptr_type, which is suitable
% for using in argument specification for codegen.
%
% m2c_opaque_ptr(var, [type], [offset])
% When called in MATLAB, it creates a pointer to the data in a
% numeric array. It also stores a reference to the mxArray struct of
% the numeric array for integrity checking.
% When called in code genration, it checks to make sure that the pointer
% is still valid for the mxArray object, and then maps the data field
% to pointers.
%
% m2c_opaque_ptr(opaque_obj, [type], [offset])
% When called in MATLAB, it creates a pointer to the data field of the opaque_obj. 
% When called in code genration, it maps the data field into pointers.
%
% In all the above cases, if offset (int32) is specified, then the pointer
% is shifted by offset bytes.
%
% See also m2c_opaque_obj, m2c_opaque_ptr_const

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

if nargin<2; type = 'void *'; end

ptr = coder.opaque(type);
if isstruct(var) && isfield(var, 'parent') && isfield(var, 'offset')
    ptr = castdata(type, var.data);

    % Verify parent mxArray still has the same address
    parent = castdata('mxArray *', var.parent);
    m2c_chk_opaque_ptr(ptr, parent, var.offset);
    if (nargin<4 || ~varargin{1}) && length(var.type)>6 && isequal(var.type(1:6),'const ')
        m2c_warn('m2c_opaque_ptr:ConstPtr', 'Discarding the const modifier of an m2c_opaque_ptr.');
    end    
elseif isstruct(var) && isfield(var, 'data') && isequal(class(var.data), 'uint8')
    ptr = cast2ptr(type, var.data);
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
    ptr = m2c_offset_ptr(ptr, int32(offset));
end
end

function ptr = m2c_offset_ptr(ptr, n) %#codegen
%Offset a pointer by n bytes
%   ptr = M2C_OFFSET_PTR(ptr, offset)

coder.inline('always');

ptr = coder.ceval('M2C_OFFSET_PTR', ptr, int32(n));
end

function ptr = cast2ptr(type, data)
coder.inline('always');

ptr = coder.opaque(type);
ptr = coder.ceval(['(' type ')'], coder.rref(data));
end
