function output = MPI_Aint_array(varargin) %#codegen
% Defines an array of MPI_Aint.
%
% MPI_Aint_array() returns a definition of m2c_opaque_type,
% suitable in the type specifications for codegen.
%
% MPI_Aint_array(n)
% constructs an n-by-1 array of objects of the given base data.
%
% MPI_Aint_array(obj, n) or MPI_Aint_array(obj, n, false)
% maps an MPI_Aint_array object into a corresponding C type based on
% context.
%
% MPI_Aint_array(obj, n, 'wrap') or MPI_Aint_array(obj, n, true) 
% wraps n MPI_Aint objects into an array.
%
% array = MPI_Aint_array(array, 'set', i, val)
% Set the ith-entry in MPI_Aint_array to the given value, where i is a
% one-based index, and vec is an opaque type.
%
% val = MPI_Aint_array(array, 'get', i)
% Obtain the ith entry in MPI_Aint_array, where i is one-based.

coder.inline('always');
coder.cinclude('mpi.h');

if nargin==1 && isnumeric(varargin{1})
    output = m2c_opaque_array('MPI_Aint', varargin{1}, mpi_get_sizeof('MPI_Aint'));
else
    output = m2c_opaque_array('MPI_Aint', varargin{:});
end
