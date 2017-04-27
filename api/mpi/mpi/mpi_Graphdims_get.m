function [nnodes, nedges, info, toplevel] = mpi_Graphdims_get(comm)
%mpi_Graphdims_get  Retrieves Cartesian topology information associated
%                  with a communicator
%
%  [nnodes, nedges, info] = mpi_Graphdims_get(comm)
%
%Input arguments
%  comm         communicator for group with graph structure (MPI_Comm)
%Output arguments
%  nnodes - number of nodes in graph (int32)
%  nedges - number of edges in graph (int32)
%  info   - return code (int32)
%
% C interface:
% int mpi_Graphdims_get(MPI_Comm comm, int *nnodes, int *nedges)
% http://mpi.deino.net/mpi_functions/mpi_Graphdims_get.html

%#codegen -args {MPI_Comm}


info = int32(0); %#ok<NASGU>
nnodes = int32(0);
nedges = int32(0);
info = coder.ceval('MPI_Graphdims_get', MPI_Comm(comm), ...
    coder.wref(nnodes), coder.wref(nedges));

toplevel = nargout>3;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Graphdims_get failed with error message %s\n', mpi_Error_string(info))
end
