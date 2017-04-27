function output = MPI_Request_array(varargin) %#codegen
% Defines an array of MPI_Request.
%
% MPI_Request_array() returns a definition of m2c_opaque_type,
% suitable in the type specifications for codegen.
%
% MPI_Request_array(n)
% constructs an n-by-1 array of objects of the given base data.
%
% MPI_Request_array(obj, n) or MPI_Request_array(obj, n, false)
% maps an MPI_Request_array object into a corresponding C type based on
% context.
%
% MPI_Request_array(obj, n, 'wrap') or MPI_Request_array(obj, n, true) 
% wraps n MPI_Request objects into an array.
%
% array = MPI_Request_array(array, 'set', i, val)
% sets the ith-entry in MPI_Request_array to the given value, where i is a
% one-based index, and vec is an opaque type.
%
% val = MPI_Request_array(array, 'get', i)
% obtains the ith entry in MPI_Request_array, where i is one-based.

coder.inline('always');
coder.cinclude('mpi.h');

if nargin==1 && isnumeric(varargin{1})
    output = m2c_opaque_array('MPI_Request', varargin{1}, mpi_get_sizeof('MPI_Request'));
else
    output = m2c_opaque_array('MPI_Request', varargin{:});
end
