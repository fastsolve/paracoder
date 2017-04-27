function [newtype, info, toplevel] = mpi_Type_contiguous(count, oldtype)
%mpi_Type_contiguous   Creates a contiguous datatype
%
%  [newtype, info] = mpi_Type_contiguous(count, oldtype)
%
%Input arguments:
%  count     replication count (nonnegative int32)
%  oldtype   old datatype (MPI_Datatype)
%
%Output arguments:
%  newtype   new datatype (MPI_Datatype)
%  info      return code (int32)
%
% SEE ALSO   mpi_Type_free
%
% C interface:
% int MPI_Type_contiguous(int count, MPI_Datatype oldtype, MPI_Datatype *newtype)
% http://mpi.deino.net/mpi_functions/MPI_Type_contiguous.html

%#codegen -args {int32(0), MPI_Datatype}

    
info = int32(0); %#ok<NASGU>
newtype0 = coder.opaque('MPI_Datatype');

info = coder.ceval('MPI_Type_contiguous', int32(count), MPI_Datatype(oldtype), ...
    coder.wref(newtype0));

toplevel = nargout>2;
newtype = MPI_Datatype(newtype0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_contiguous failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! var2 = zeros(10,10);

%! newtype = mpi_Type_contiguous(int32(10), MPI_DOUBLE);
%! newtype = mpi_Type_commit(newtype);

%! count = int32(10);
%! [req,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, newtype, int32(0), int32(1), comm);
%! assert(info==0);
%! info = mpi_Send(m2c_opaque_ptr_const(var1), count, newtype, int32(0), int32(1), comm);

%! mpi_Request_free(req);
%! mpi_Type_free(newtype);
%! assert(info==0);
%! assert(isequal(var1, var2));
