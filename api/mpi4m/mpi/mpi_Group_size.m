function [size, info, toplevel] = mpi_Group_size(group)
%mpi_Group_size   Returns the size of a group
%
%  [size, info] =  mpi_Group_size (group)
%
%  group Opaque MPI_Group object.
%  size (int) number of processes in the group
%
%  info (int) return code
%
%  SEE ALSO: mpi_Group_rank
%
% C interface:
% int mpi_Group_size(MPI_Group group, int *size ) 
% http://mpi.deino.net/mpi_functions/MPI_Group_size.html

%#codegen -args {MPI_Group}

size = int32(1); info = int32(0); %#ok<NASGU>

info = coder.ceval('MPI_Group_size', MPI_Group(group), coder.wref(size));

toplevel = nargout>2;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Group_size failed with error message %s\n', mpi_Error_string(info))
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
