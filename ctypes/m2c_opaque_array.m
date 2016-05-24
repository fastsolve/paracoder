function output = m2c_opaque_array(basetype, varargin) %#codegen
% Creates or accesses an array of objects of an opaque C type.
%
% m2c_opaque_array() returns a definition of m2c_opaque_type, suitable in
% the type specifications for codegen.
%
% array = m2c_opaque_array(basedatatype, obj) maps an m2c_opaque_array 
% object into a corresponding C type based on context.
%
% array = m2c_opaque_array(basedatatype, obj, n) or 
% array = m2c_opaque_array(basedatatype, obj, n, false) maps n 
% objects into a corresponding C type based on.
%
% array = m2c_opaque_array(basedatatype, obj, n, 'wrap', [sizepe]) or 
% array = m2c_opaque_array(basedatatype, obj, n, true) wraps n
% C objects into a corresponding opaque array in MATLAB.
%
% array = m2c_opaque_array(basedatatype, n, [sizepe])
% Construct an n-by-1 array of objects of the given base data. The argument
% sizepe is optional and specifies the number of bytes per object. If not
% provided, then m2c_opaque_array will obtain the size at runtime.
%
% array = m2c_opaque_array(basedatatype, array, 'set', i, val)
% Set the ith-entry in m2c_opaque_array to the given value, where i is a
% one-based index, and vec is an opaque type.
%
% val = m2c_opaque_array(basedatatype, array, 'get', i)
% Obtain the ith entry in m2c_opaque_array, where i is one-based.
% The argument basedatatyye is optional, for casting the objects
% to a different type. If present, basedatatype must be a constant
% string known at compile time. It is user's responsibility to ensure
% the basedatatype is valid.
%
% Note: This is an advanced function useful for constructing array of opaque
%    C objects for passing to C functions. An example use is to pass an array
%    of MPI_Statas to MPI_Waitall. This is just a template implementation,
%    and in general, users should use it to implement customized versions
%    to perform error checking.
%    It is also possible to construct an array of opaque pointers, in
%    case m2c_touch may be needed to prevent the objects referenced by
%    the poniters from being garbage collected.
%
% See also m2c_opqaue_obj, m2c_opqaue_ptr, m2c_touch

coder.inline('always');

if nargin<=1
    % m2c_opaque_array or m2c_opaque_array(basedatatype)
    output = m2c_opaque_type;
elseif nargin==2 && ~isnumeric(varargin{1})
    arg = varargin{1};

    % m2c_opaque_array(basedatatype, obj)
    if ~isstruct(arg) || isempty(coder.target)
        output = arg;
    else
        output = castdata([basetype '*'], arg.data);
    end
elseif nargin==2 || nargin==3 && isnumeric(varargin{1})
    if ~isnumeric(varargin{1}) || ~ischar(basetype)
        m2c_error('m2c_opaque_array:WrongInput', ...
            ['When creating an array, the first input argument should be ', ...
            'the type name and the second argument should be the size.\n']);
    end
    
    if nargin==2
        % m2c_opaque_array(basedatatype, n)
        output = m2c_opaque_obj(basetype, [], int32(varargin{1}));
    else
        % m2c_opaque_array(basedatatype, n, sizepe)
        output = m2c_opaque_obj(basetype, [], int32(varargin{1}), int32(varargin{2}));
    end
elseif ~isnumeric(varargin{1}) && isnumeric(varargin{2})
    if nargin==3 || ~ischar(varargin{3}) || ~varargin{3}
        % m2c_opaque_array(basedatatype, obj, n)
        % m2c_opaque_array(basedatatype, obj, n, false)
        output = varargin{1};
    elseif nargin<5
        % m2c_opaque_array(basedatatype, obj, n, 'wrap'|true)
        output = m2c_opaque_obj(basetype, varargin{1}, int32(varargin{2}));
    else
        % m2c_opaque_array(basedatatype, obj, n, 'wrap'|true, sizepe)
        output = m2c_opaque_obj(basetype, varargin{1}, int32(varargin{2}), int32(varargin{4}));
    end
elseif ischar(varargin{2}) && isequal(varargin{2}, 'set')
    % array = m2c_opaque_array(basedatatype, array, 'set', i, val)
    if nargin<5
        m2c_error('m2c_opaque_array:WrongInput', ...
            'When setting a value, there must be 5 arguments.\n');
    end
    
    i = int32(varargin{3});
    output = varargin{1};
    
    if m2c_debug && i<1 || i>output.nitems
        m2c_error('m2c_opaque_array:IndexOutOfBound', ...
            'Index %d is out of bound when setting an entry in m2c_opaque_array.\n', i);
    end
    
    sizepe = fix(length(output.data)/output.nitems);
    offset = int32(i-1) * sizepe;
    
    % copy val into the ith entry
    if isstruct(varargin{4})
        val = varargin{4};
    else
        val = m2c_opaque_obj(basetype, varargin{4}, true);
    end
    output.data(offset+1:offset+sizepe) = val.data;
elseif ischar(varargin{2}) && isequal(varargin{2}, 'get')
    % val = m2c_opaque_array(basedatatype, array, 'get', i)
    i = int32(varargin{3});
    arr = varargin{1};
    
    if m2c_debug && i<1 || i>arr.nitems
        m2c_error('m2c_opaque_array:IndexOutOfBound', ...
            'Index %d is out of bound when getting an entry in m2c_opaque_array.\n', i);
    end
    
    sizepe = fix(length(arr.data)/arr.nitems);
    offset = int32(i-1) * sizepe;
    
    output = m2c_opaque_obj(basetype, arr.data(offset+1:offset+n), true);
else
    error('Incorrect input arguments.');
end
