function [ndims, info, toplevel] = mpi_Cartdim_get(comm)
%mpi_Cartdim_get  Retrieves Cartesian topology information associated
%                  with a communicator
%
%  [ndims, info] = mpi_Cartdim_get(comm)
%
%Input arguments
%  comm         Communicator with cartesian structure
%Output arguments
%  ndims       number of dimensions of the cartesian structure
%  info        return code (int32)
%
% C interface:
% int mpi_Cartdim_get(MPI_Comm comm, int *ndims)
% http://mpi.deino.net/mpi_functions/mpi_Cartdim_get.html

%#codegen -args {MPI_Comm}


info = int32(0); %#ok<NASGU>
ndims = int32(0);
info = coder.ceval('MPI_Cartdim_get', MPI_Comm(comm), coder.wref(ndims));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Cartdim_get failed with error message %s\n', mpi_Error_string(info))
end
