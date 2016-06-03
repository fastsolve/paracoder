function output = m2c_opaque_array(basetype, varargin) %#codegen
% Creates or accesses an array of objects of an opaque C type.
%
% m2c_opaque_array() returns a definition of m2c_opaque_type, suitable in
% the type specifications for codegen.
%
% array = m2c_opaque_array(basedatatype, obj)
% array = m2c_opaque_array(basedatatype, obj, n)
% array = m2c_opaque_array(basedatatype, obj, n, false) maps an
% m2c_opaque_array object into a corresponding C type based on context.
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
% See also m2c_opqaue_ptr, m2c_opqaue_ptr_const

% Note: This is an advanced function for constructing array of opaque
%    C objects for passing to C functions. In general, it must be used in
%    conjunction with m2c_opqaue_ptr or m2c_opqaue_ptr_const.
%    It can be used to pass arrays of opaque objects C code.
%    This is just a  template implementation, which should be called
%    to implement customized versions for specific array types.
%    For an example of its usage, see MMPI/mpi/MPI_Datatype_array and
%    MMPI/mpi/mpi_Alltoallw.

coder.inline('always');

if nargin<=1
    % m2c_opaque_array or m2c_opaque_array(basedatatype)
    output = m2c_opaque_type;
elseif (isstruct(varargin{1}) || isa(varargin{1}, 'uint8')) && ...
        (nargin<=3 || nargin==4 && ~ischar(varargin{3}) && ~varargin{3})
    arg = varargin{1};
    
    % m2c_opaque_array(basedatatype, arg)
    if ~isstruct(arg) || isempty(coder.target)
        output = arg;
    else
        % It is necessary to extract out the data field in order to be used
        % in conjunction with m2c_opqaue_ptr, m2c_opqaue_ptr_const. Before
        % extracting, check the data type was correct
        if ~isequal(arg.type, basetype)
            m2c_error('m2c_opaque_array:TypeMismatch', ...
                'Incorrect data type &s. Expected %s.\n', ...
                [arg.type char(0)], [basetype char(0)]);
        end
        output = arg.data;
    end
elseif nargin==2 || nargin==3 && isnumeric(varargin{1})
    if ~isnumeric(varargin{1}) || ~ischar(basetype)
        m2c_error('m2c_opaque_array:WrongInput', ...
            ['When creating an array, the first input argument should be ', ...
            'the type name and the second argument should be the size.\n']);
    end
    
    if isempty(coder.target)
        if nargin==2
            % m2c_opaque_array(basedatatype, n)
            output = m2c_opaque_obj(basetype, [], int32(varargin{1}));
        else
            % m2c_opaque_array(basedatatype, n, sizepe)
            output = m2c_opaque_obj(basetype, [], int32(varargin{1}), int32(varargin{2}));
        end
    else
        if nargin>2
            sizepe = int32(varargin{2});
        else
            sizepe = int32(0);
            sizepe = coder.ceval('sizeof', coder.opaque('ctype',basetype));
        end
        
        output = zeros(int32(varargin{1}) * sizepe);
    end
elseif (nargin==4 || nargin==5) && isnumeric(varargin{2}) && ...
        (ischar(varargin{3}) || varargin{3})
    if ischar(varargin{3}) && ~isequal(varargin{3}, 'wrap')
        m2c_error('m2c_opaque_array:WrongInput', ...
            'When 3rd argument is string, it must be ''wrap''.\n');
    end
    
    % array = m2c_opaque_array(basedatatype, obj, n, 'wrap', [sizepe]) or
    % array = m2c_opaque_array(basedatatype, obj, n, true, [sizepe])
    if isstruct(varargin{1})
        output = varargin{1};
    else
        output = m2c_opaque_obj(basetype, varargin{1}, varargin{2}, varargin{4:end});
    end
elseif nargin==5 && ischar(varargin{2}) && isequal(varargin{2}, 'set')
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
    
    % copy val into the ith entry
    if isstruct(varargin{4})
        val = varargin{4};
    else
        val = m2c_opaque_obj(basetype, varargin{4}, true);
    end
    
    if isfield(output, 'data')
        sizepe = int32(fix(length(output.data)/output.nitems));
    else
        sizepe = int32(0);
        sizepe = coder.ceval('sizeof', coder.opaque('ctype', basetype));
    end
    offset = int32(i-1) * sizepe;
    output.data(offset+1:offset+sizepe) = val.data;
elseif nargin==4 && ischar(varargin{2}) && isequal(varargin{2}, 'get')
    % val = m2c_opaque_array(basedatatype, array, 'get', i)
    i = int32(varargin{3});
    arr = varargin{1};
    
    if m2c_debug && i<1 || i>arr.nitems
        m2c_error('m2c_opaque_array:IndexOutOfBound', ...
            'Index %d is out of bound when getting an entry in m2c_opaque_array.\n', i);
    end
    
    if isfield(arr, 'data')
        sizepe = int32(fix(length(arr.data)/arr.nitems));
    else
        sizepe = int32(0);
        sizepe = coder.ceval('sizeof', coder.opaque('ctype', basetype));
    end
    
    offset = int32(i-1) * sizepe;
    
    output = m2c_opaque_obj(basetype, arr.data(offset+1:offset+sizepe), true);
else
    error('Incorrect input arguments.');
end
end
