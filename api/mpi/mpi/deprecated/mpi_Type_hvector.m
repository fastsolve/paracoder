function [newtype, info, toplevel] = mpi_Type_hvector(count, blocklen, stride, oldtype)
%mpi_Type_hvector   Creates a vector (strided) datatype with offset in bytes
%
%  [newtype, info] = mpi_Type_hvector(count, blocklen, stride, oldtype)
%
%Input arguments:
%  count     number of blocks (int32)
%  blocklen  number of elements in each block (int32)
%  stride    nnumber of bytes between start of each block (MPI_Aint)
%  oldtype   old datatype (MPI_Datatype)
%
%Output arguments:
%  newtype   new datatype (MPI_Datatype)
%  info      return code (int32)
%
% SEE ALSO   mpi_Type_free
%
% The MPI-2 standard deprecated this routine. This routine is replaced by
%     MPI_Type_create_hvector.
%
% C interface:
% int MPI_Type_hvector(int count,int blocklen, MPI_Aint stride, 
%                      MPI_Datatype oldtype, MPI_Datatype *newtype)
% http://mpi.deino.net/mpi_functions/MPI_Type_hvector.html

%#codegen -args {int32(0), int32(0), MPI_Aint, MPI_Datatype}

    
info = int32(0);
newtype0 = coder.opaque('MPI_Datatype');

info = coder.ceval('MPI_Type_hvector', count, blocklen, ...
    MPI_Aint(stride), MPI_Datatype(oldtype), coder.wref(newtype0));

toplevel = nargout>2;
newtype = MPI_Datatype(newtype0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_hvector returned error code %d\n', info)
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! var2 = zeros(10,10);

%! newtype = mpi_Type_hvector(int32(1), int32(10), MPI_Aint(80), MPI_DOUBLE);
%! newtype = mpi_Type_commit(newtype);

%! count = int32(10);
%! [req,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, newtype, int32(0), int32(1), comm);
%! assert(info==0);
%! info = mpi_Send(m2c_opaque_ptr_const(var1), count, newtype, int32(0), int32(1), comm);

%! mpi_Request_free(req);
%! mpi_Type_free(newtype);
%! assert(info==0);
%! assert(isequal(var1, var2));
