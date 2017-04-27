function output = MPI_Status_array(varargin) %#codegen
% Defines an array of MPI_Status.
%
% MPI_Status_array() returns a definition of m2c_opaque_type,
% suitable in the type specifications for codegen.
%
% MPI_Status_array(n)
% constructs an n-by-1 array of objects of the given base data.
%
% MPI_Status_array(obj, n) or MPI_Status_array(obj, n, false) 
% maps n MPI_Status_array objects into a corresponding C type based on
% context.
%
% MPI_Status_array(obj, n, 'wrap') or MPI_Status_array(obj, n, true) 
% wraps n MPI_Status objects into an array.
%
% array = MPI_Status_array(array, 'set', i, val)
% sets the ith-entry in MPI_Status_array to the given value, where i is a
% one-based index, and vec is an opaque type.
%
% val = MPI_Status_array(array, 'get', i)
% obtains the ith entry in MPI_Status_array, where i is one-based.
%
% val = MPI_Status_array(arg, 'get', i, field)
% obtains the field of the ith-entry in an MPI_Status array, where
% i is one-based, and field is a character string. The filed can be
% 'source' (or 'MPI_SOURCE'), 'tag' (or 'MPI_TAG'), and 'error (or 'MPI_ERROR').
%
% See also MPI_Status, MPI_Request, MPI_Request_array

coder.inline('always');
coder.cinclude('mpi.h');

if nargin==1 && isnumeric(varargin{1})
    output = m2c_opaque_array('MPI_Status', varargin{1}, mpi_get_sizeof('MPI_Status'));
elseif nargin==4 && ischar(varargin{4})
    arg = varargin{1};

    i = int32(varargin{3});
    if m2c_debug && isstruct(arg) && (i<1 || i>arg.nitems)
        m2c_error('Index is out of bound');
    end

    stat = m2c_opaque_array('MPI_Status', varargin{1}, 'get', i);
    output = mpi_get_status_field(stat, varargin{4});
else
    output = m2c_opaque_array('MPI_Status', varargin{:});
end
