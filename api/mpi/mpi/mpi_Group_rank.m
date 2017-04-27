function [rank, info, toplevel] = mpi_Group_rank(group)
%mpi_Group_rank  Determines the rank of the calling process in the communicator
%
%  [rank, info] =  mpi_Group_rank (group)
%
%  group       Opaque MPI_Group object.
%  rank (int) rank of the calling process in the group
%
%  info (int) return code
%
%  SEE ALSO: mpi_Group_size
%
% C interface:
% int mpi_Group_rank(MPI_Group group, int *rank ) 
% http://mpi.deino.net/mpi_functions/MPI_Group_rank.html

%#codegen -args {MPI_Group}

 
info = int32(0); %#ok<NASGU>
rank = int32(0);

info = coder.ceval('MPI_Group_rank', MPI_Group(group), coder.wref(rank));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Group_rank failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! group = mpi_Comm_group(MPI_COMM_WORLD);
%! [size,info] = mpi_Group_size(group);
%! assert(size == 1);
%! [rank,info] = mpi_Group_rank(group);
%! assert(rank == 0);
