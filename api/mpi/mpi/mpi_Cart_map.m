function [newrank, info, toplevel] = mpi_Cart_map(comm, ndims, dims, periods)
%mpi_Cart_map    Maps process to Cartesian topology information
%
%  [newrank, info] = mpi_Cart_map(comm, ndims, dims, periods)
%
%Input arguments:
%  comm      A communicator object
%  ndims     number of dimensions of cartesian grid
%  dims      integer array of size ndims specifying the number of 
%            processes in each dimension
%  periods   logical array of size ndims specifying whether the
%            grid is periodic (true) or not (false) in each dimension
%Output arguments:
%  newrank   reordered rank of the calling process; MPI_UNDEFINED if 
%            calling process does not belong to grid (integer)
%  info      return code
%
% SEE ALSO mpi_Cart_create
%
% C interface:
% int MPI_Cart_map(MPI_Comm comm, int ndims, int *dims,
%     int *periods, int reorder,, MPI_Comm *newcomm)
% http://mpi.deino.net/mpi_functions/MPI_Cart_map.html

%#codegen -args {MPI_Comm, int32(0), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(int32(0), [inf,1])}


info = int32(0); %#ok<NASGU>
newrank = int32(0);

if length(dims) < ndims
    m2c_error('mpi_Cart_map:OutOfBound', 'dims array is too small.');
end
if length(periods) < ndims
    m2c_error('mpi_Cart_map:OutOfBound', 'periods array is too small.');
end

info = coder.ceval('MPI_Cart_map', MPI_Comm(comm), ndims, ...
    coder.rref(dims), coder.rref(periods), coder.wref(newrank));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Cart_map failed with error message %s\n', mpi_Error_string(info))
end
