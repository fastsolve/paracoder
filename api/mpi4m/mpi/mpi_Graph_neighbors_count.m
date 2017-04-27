function [nneighbors, info, toplevel] = mpi_Graph_neighbors_count(comm, rank)
%mpi_Graph_neighbors_count  Returns the number of neighbors of a node
%       associated with a graph topology
%
%  [nneighbors, info] = mpi_Graph_neighbors_count(comm, rank)
%
%Input arguments
%  comm  - Communicator with graph topology (MPI_Comm)
%  rank  - rank of process in group of comm (int32)
%Output arguments
%  nneighbors  number of neighbors of specified process
%  info        return code (int32)
%
% C interface:
% int mpi_Graph_neighbors_count(MPI_Comm comm, int rank, int *nneighbors)
% http://mpi.deino.net/mpi_functions/mpi_Graph_neighbors_count.html

%#codegen -args {MPI_Comm, int32(0)}


info = int32(0); %#ok<NASGU>
nneighbors = int32(0);
info = coder.ceval('MPI_Graph_neighbors_count', MPI_Comm(comm), rank, coder.wref(nneighbors));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Graph_neighbors_count failed with error message %s\n', mpi_Error_string(info))
end
