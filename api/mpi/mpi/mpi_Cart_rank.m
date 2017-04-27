function [rank, info, toplevel] = mpi_Cart_rank(comm, coords)
%mpi_Cart_rank   Determines process rank in communicator given Cartesian location
%
%  [rank, info] = mpi_Cart_rank(comm, coords)
%
%Input arguments:
%  comm      a communicator object (MPI_Comm)
%  coords    integer array (of size ndims) containing the Cartesian 
%            coordinates of specified process
%Output arguments:
%  rank      rank of a process within group of comm
%  info      return code
%
% SEE ALSO mpi_Cart_coords
%
% C interface:
% int MPI_Cart_rank(MPI_Comm comm, int *coords, int rank)
% http://mpi.deino.net/mpi_functions/MPI_Cart_rank.html

%#codegen -args {MPI_Comm, coder.typeof(int32(0), [inf,1])}


info = int32(0); %#ok<NASGU>
rank = int32(0);

info = coder.ceval('MPI_Cart_rank', MPI_Comm(comm), ...
    coder.rref(coords), coder.wref(rank));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Cart_rank failed with error message %s\n', mpi_Error_string(info))
end
