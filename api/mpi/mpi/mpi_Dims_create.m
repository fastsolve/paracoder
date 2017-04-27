function [dims, info, toplevel] = mpi_Dims_create(nnodes, ndims)
%mpi_Dims_create     Creates a division of processors in a cartesian grid
%
%  [dims, info] = mpi_Dims_create(nnodes, ndims)
%
%Input arguments:
%  nnodes   number of nodes in a grid (integer)
%  ndims    number of cartesian dimensions (integer)
%Output arguments:
%  dims     integer array of size ndims specifying the number of nodes in each dimension
%  info     return code
%
% C interface:
% int MPI_Dims_create(int nnodes, int ndims, int *dims)
% http://mpi.deino.net/mpi_functions/MPI_Dims_create.html

%#codegen -args {int32(0), int32(0)}


info = int32(0); %#ok<NASGU>
dims = zeros(ndims, 1, 'int32');

info = coder.ceval('MPI_Dims_create', nnodes, ndims, coder.ref(dims));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Dims_create failed with error message %s\n', mpi_Error_string(info))
end
