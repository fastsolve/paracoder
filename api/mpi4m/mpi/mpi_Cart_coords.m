function [coords, info, toplevel] = mpi_Cart_coords(comm, rank, maxdims)
%mpi_Cart_coords     Determines  process  coords  in cartesian topology given rank in group
%
%  [coords, info] = mpi_Cart_coords(comm, rank, maxdims)
%
%Input arguments:
%  comm      a communicator object (MPI_Comm)
%  rank      rank of a process within group of comm
%  maxdims   length of vector coords in the calling program
%Output arguments:
%  coords    integer array (of size ndims ) containing the Cartesian  
%            coordinates of specified process
%  info      return code
%
% SEE ALSO mpi_Cart_rank
%
% C interface:
% int MPI_Cart_coords(MPI_Comm comm, int rank, int maxdims, int *coords)
% http://mpi.deino.net/mpi_functions/MPI_Cart_coords.html

%#codegen -args {MPI_Comm, int32(0), int32(0)}


info = int32(0); %#ok<NASGU>
coords = zeros(maxdims, 1, 'int32');

info = coder.ceval('MPI_Cart_coords', MPI_Comm(comm), rank, ...
    maxdims, coder.ref(coords));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Cart_coords failed with error message %s\n', mpi_Error_string(info))
end
