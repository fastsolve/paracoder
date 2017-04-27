function [dims, periods, coords, info, toplevel] = mpi_Cart_get(comm, maxdims)
%mpi_Cart_get  Retrieves  Cartesian  topology information associated with a communicator
%
%  [dims, periods, coords, info] = mpi_Cart_get(comm, maxdims)
%
%Input arguments:
%  comm      a communicator object (MPI_Comm)
%  maxdims   length of vector coords in the calling program
%Output arguments:
%  dims      number  of  processes  for each cartesian dimension
%  periods   periodicity (true/false) for each cartesian  dimension
%  coords    integer array (of size ndims ) containing the Cartesian  
%            coordinates of specified process
%  info      return code
%
% SEE ALSO mpi_Cart_rank
%
% C interface:
% int MPI_Cart_get(MPI_Comm comm, int maxdims, int *dims, int *periods, int *coords)
% http://mpi.deino.net/mpi_functions/MPI_Cart_coords.html

%#codegen -args {MPI_Comm, int32(0)}


info = int32(0); %#ok<NASGU>
dims = zeros(maxdims, 1, 'int32');
periods = zeros(maxdims, 1, 'int32');
coords = zeros(maxdims, 1, 'int32');

info = coder.ceval('MPI_Cart_get', MPI_Comm(comm), ...
    maxdims, coder.ref(dims), coder.ref(periods), coder.ref(coords));

toplevel = nargout>4;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Cart_get failed with error message %s\n', mpi_Error_string(info))
end
