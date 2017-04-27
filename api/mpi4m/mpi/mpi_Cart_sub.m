function [newcomm, info, toplevel] = mpi_Cart_sub(comm, remain_dims)
%mpi_Cart_sub  Duplicates an existing communicator with all its cached information
%
%  [newcomm, info] = mpi_Cart_sub(comm, remaind_dims)
%
%Input arguments
%  comm         Communicator with cartesian structure
%  remain_dims  the i th entry of  remain_dims  specifies  whether the ith
%               dimension is kept in the subgrid (true) or is dropped (false)
%Output arguments
%  newcomm     communicator containing the subgrid that includes the calling process
%  info        return code (int32)
%
% C interface:
% int MPI_Cart_sub(MPI_Comm comm, int *remain_dims, MPI_Comm *newcomm)
% http://mpi.deino.net/mpi_functions/MPI_Cart_sub.html

%#codegen -args {MPI_Comm, coder.typeof(int32(0), [inf,1])}

info = int32(0); %#ok<NASGU>


newcomm0 = coder.opaque('MPI_Comm');
info = coder.ceval('MPI_Cart_sub', MPI_Comm(comm), ...
    coder.rref(remain_dims), coder.wref(newcomm0));

toplevel = nargout>2;
newcomm = MPI_Comm(newcomm0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Cart_sub failed with error message %s\n', mpi_Error_string(info))
end
