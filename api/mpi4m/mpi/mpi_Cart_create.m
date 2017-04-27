function [newcomm, info, toplevel] = mpi_Cart_create(comm, ...
    ndims, dims, periods, reorder)
%mpi_Cart_create    Makes a new communicator to which topology 
%                    information has been attached
%
%  [newcomm, info] = mpi_Cart_create(comm, ndims, dims, periods, reorder)
%
%Input arguments:
%  comm      A communicator object
%  ndims     number of dimensions of cartesian grid
%  dims      integer array of size ndims specifying the number of 
%            processes in each dimension
%  periods   logical array of size ndims specifying whether the
%            grid is periodic (true) or not (false) in each dimension
%  reorder   ranking may be reordered (true) or not (false) (int32)
%Output arguments:
%  newcomm   A new commungroup, which is a subset of the group of comm
%  info      return code
%
% SEE ALSO mpi_Comm_free
%
% C interface:
% int MPI_Cart_create(MPI_Comm comm, int ndims, int *dims,
%     int *periods, int reorder,, MPI_Comm *newcomm)
% http://mpi.deino.net/mpi_functions/MPI_Cart_create.html

%#codegen -args {MPI_Comm, int32(0), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(int32(0), [inf,1]), int32(0)}


info = int32(0); %#ok<NASGU>
newcomm0 = coder.opaque('MPI_Comm');

if length(dims) < ndims
    m2c_error('mpi_Cart_create:OutOfBound', 'dims array is too small.');
end
if length(periods) < ndims
    m2c_error('mpi_Cart_create:OutOfBound', 'periods array is too small.');
end

info = coder.ceval('MPI_Cart_create', MPI_Comm(comm), ndims, ...
    coder.rref(dims), coder.rref(periods), reorder, coder.wref(newcomm0));
    
toplevel = nargout>2;
newcomm = MPI_Comm(newcomm0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Cart_create failed with error message %s\n', mpi_Error_string(info))
end
