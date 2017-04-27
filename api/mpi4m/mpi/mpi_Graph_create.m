function [newcomm, info, toplevel] = mpi_Graph_create(comm, nnodes, index, edges, reorder)
%mpi_Graph_create    Makes a new communicator to which topology 
%                    information has been attached
%
%  [newcomm, info] = mpi_Graph_create(comm, ndims, dims, periods, reorder)
%
%Input arguments:
%  comm      a communicator object (MPI_Comm)
%  nnodes    number of nodes in graph ((int32))
%  index     array of integers describing node degrees (int32)
%  edges     array of integers describing graph edges (int32)
%  reorder   ranking may be reordered (true) or not (false) (int32)
%Output arguments:
%  newcomm   A new commungroup, which is a subset of the group of comm (MPI_Comm)
%  info      return code (int32)
%
% SEE ALSO mpi_Comm_free
%
% C interface:
% int MPI_Graph_create(MPI_Comm comm, int nnodes, int *index,
%     int *edges, int reorder,, MPI_Comm *newcomm)
% http://mpi.deino.net/mpi_functions/MPI_Graph_create.html

%#codegen -args {MPI_Comm, int32(0), coder.typeof(int32(0), [inf,1]),
%#codegen coder.typeof(int32(0), [inf,1]), int32(0)}


info = int32(0); %#ok<NASGU>
newcomm0 = coder.opaque('MPI_Comm');

if length(index) < nnodes
    m2c_error('mpi_Graph_create:OutOfBound', 'index array is too small.');
end
if length(edges) < sum(index(1:nnodes))
    m2c_error('mpi_Graph_create:OutOfBound', 'edges array is too small.');
end

info = coder.ceval('MPI_Graph_create', MPI_Comm(comm), nnodes, ...
    coder.rref(index), coder.rref(edges), reorder, coder.wref(newcomm0));

toplevel = nargout>2;
newcomm = MPI_Comm(newcomm0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Graph_create failed with error message %s\n', mpi_Error_string(info))
end
