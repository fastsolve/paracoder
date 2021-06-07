function [info, toplevel] = mpi_Bcast(ptr, count, datatype, root, comm)
%mpi_Bcast   Broadcasts a message from the process with rank root to all other processes of the group.
%
%  info = mpi_Bcast (ptr, count, datatype, root, comm)
%
%  ptr       an m2c_opaque_ptr to a variable
%  count     Number of items.
%  datatype  Opaque MPI_Datatype object (see MPI_Datatype).
%  root      rank of broadcast root
%  comm      Opaque MPI_Comm object (see MPI_Comm)
%
%  info (int)	return code
%
%  SEE ALSO: mpi_Barrier, mpi_Scatter, mpi_Gather, mpi_Reduce
%
%  mpi_Bcast is a collective operation on comm (all ranks must call it)
%
% C interface:
% int MPI_Bcast(void *buffer, int count, MPI_Datatype datatype,
%		        int root, MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Bcast.html

%#codegen -args {m2c_opaque_ptr, int32(0), MPI_Datatype, int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(ptr) && coder.target('MATLAB')
    if (ptr.nbytes-ptr.offset < count*mpi_Type_size(datatype))
        m2c_error('mpi_Bcast:OutOfBound','Message size is larger than variable size.');
    end
end

info = coder.ceval('MPI_Bcast', m2c_opaque_ptr(ptr), ...
    int32(count), MPI_Datatype(datatype), int32(root), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Bcast failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var = rand(10,10);
%! count = int32(numel(var));
%!
%! info = mpi_Bcast(m2c_opaque_ptr(var), count, MPI_DOUBLE, int32(0), comm);
%! assert(info==0);
