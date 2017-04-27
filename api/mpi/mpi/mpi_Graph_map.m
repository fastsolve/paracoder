function [newrank, info, toplevel] = mpi_Graph_map(comm, nnodes, index, edges)
%mpi_Graph_map    Maps process to graph topology information
%
%  [newrank, info] = mpi_Graph_map(comm, nnodes, index, edges)
%
%Input arguments:
%  comm      A communicator object
%  nnodes    number of graph nodes (int32)
%  index     integer   array   specifying   the   graph   structure
%  edges     integer array specifying the graph structure
%Output arguments:
%  newrank   reordered rank of the calling process; MPI_UNDEFINED if 
%            calling process does not belong to grid (integer)
%  info      return code
%
% SEE ALSO mpi_Graph_create
%
% C interface:
% int MPI_Graph_map(MPI_Comm comm, int nnodes, int *index,
%     int *edges, int reorder,, MPI_Comm *newcomm)
% http://mpi.deino.net/mpi_functions/MPI_Graph_map.html

%#codegen -args {MPI_Comm, int32(0), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(int32(0), [inf,1])}


info = int32(0); %#ok<NASGU>
newrank = int32(0);

if length(index) < nnodes
    m2c_error('mpi_Graph_map:OutOfBound', 'index array is too small.');
end
if length(edges) < nnodes
    m2c_error('mpi_Graph_map:OutOfBound', 'edges array is too small.');
end

info = coder.ceval('MPI_Graph_map', MPI_Comm(comm), nnodes, ...
    coder.rref(index), coder.rref(edges), coder.wref(newrank));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Graph_map failed with error message %s\n', mpi_Error_string(info))
end
