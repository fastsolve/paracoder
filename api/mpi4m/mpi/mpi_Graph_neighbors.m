function [neighbors, info, toplevel] = mpi_Graph_neighbors(comm, rank, maxneighbors)
%mpi_Graph_neighbors     Determines  process  neighbors  in cartesian topology given rank in group
%
%  [neighbors, info] = mpi_Graph_neighbors(comm, rank, maxneighbors)
%
%Input arguments:
%  comm           communicator with graph topology (MPI_Comm)
%  rank           rank of a process within group of comm
%  maxneighbors   size of array neighbors
%Output arguments:
%  neighbors   ranks of processes that are neighbors to specified process
%  info         return code
%
% SEE ALSO mpi_Graoh_create
%
% C interface:
% int MPI_Graph_neighbors(MPI_Comm comm, int rank, int maxneighbors, int *neighbors)
% http://mpi.deino.net/mpi_functions/MPI_Graph_neighbors.html

%#codegen -args {MPI_Comm, int32(0), int32(0)}


info = int32(0); %#ok<NASGU>
neighbors = zeros(maxneighbors, 1, 'int32');

info = coder.ceval('MPI_Graph_neighbors', MPI_Comm(comm), rank, ...
    maxneighbors, coder.ref(neighbors));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Graph_neighbors failed with error message %s\n', mpi_Error_string(info))
end
