function obj = m2c_opaque_obj(type, arg, wrap, sizepe) %#codegen
%Maps between C opaque object and a MATLAB structure.
%
%  m2c_opaque_obj() or m2c_opaque_obj(type) simply returns a
%  definition of the m2c_opaque_type, suitable in the argument type
%  specification for codegen.
%
%  m2c_opaque_obj(type, arg) or m2c_opaque_obj(type, arg, false) converts
%  arg into an object of give data type.
%
%  m2c_opaque_obj(type, arg, 'wrap') or m2c_opaque_obj(type, arg, true)
%  wraps the arg into an opaque object. This should be used if the opaque
%  object needs to be returned to MATLAB. Note that the third argument
%  must be determined at compile time.
%
% See also m2c_opaque_array, m2c_opaque_ptr

% Undocumented use:
%  obj = m2c_opaque_obj(type, arg, n, [sizepe]) wraps n objects
%  into an opaque object. This is for internal use by
%  m2c_opaque_array. Users should use m2c_opaque_array instead.

coder.inline('always');


if nargin<=1
    obj = m2c_opaque_type;
    return;
end

if isstruct(arg) && ~isequal(arg.type, type)
    m2c_error('m2c_opaque_obj:WrongInput', ...
        ['Incorrect data type %s. Expected ' type '.\n'], [arg.type char(0)]);
end

if nargin==3 && ischar(wrap) && ~isequal(wrap, 'wrap')
    m2c_error('m2c_opaque_obj:WrongInput', ...
        'When there are three arguments, the 3rd argument should be ''wrap''.\n');
end

if nargin<3 || islogical(wrap) && ~wrap
    if ~isstruct(arg) || isempty(coder.target)
        obj = arg;
        return;
    else
        obj = m2c_castdata(type, arg.data);
        return;
    end
elseif ischar(wrap) || islogical(wrap)
    nitems = 1;
else
    nitems = int32(wrap);
end

coder.varsize('obj.data', [inf,1]);
coder.varsize('obj.type', [1,inf]);
coder.varsize('obj.nitems', [1,1]);

if isempty(coder.target)
    if ~isempty(arg) || nitems==0
        arg = typecast(arg, 'uint8');
        if isrow(arg); arg = arg'; end
    elseif nargin<4
        error('When called within MATLAB with an empty data array, sizepe must be specified.');
    else
        arg = zeros(sizepe*nitems, 1, 'uint8');
    end
    obj = struct('data', arg, 'type', char(type(:)'), ...
        'nitems', int32(nitems));
else
    if nargin<4
        sizepe = int32(0);
        sizepe = coder.ceval('sizeof', coder.opaque('ctype',type));
    end
    
    % Allocate data
    data0 = coder.nullcopy(zeros(sizepe*nitems, 1, 'uint8'));
    obj = struct('data', data0, 'type', char(type(:)'), 'nitems', int32(nitems));
    if ~isempty(arg)
        ptr = coder.opaque('char *', 'NULL');
        ptr = coder.ceval('(char *)', coder.rref(arg));
        for i=int32(1):sizepe*nitems
            obj.data(i) = coder.ceval('*', ptr);
            ptr = m2c_offset_ptr(ptr, int32(1));
        end
    end
end
end
