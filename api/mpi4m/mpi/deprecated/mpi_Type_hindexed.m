function [newtype, info, toplevel] = mpi_Type_hindexed(count, blocklens, indices, oldtype)
%mpi_Type_hindexed   Creates an indexed datatype with offsets in bytes
%
%  [newtype, info] = mpi_Type_hindexed(count, blocklens, indices, oldtype)
%
%Input arguments:
%  count     number of blocks and number of entries in blocklens & indices(int32)
%  blocklens number of elements in each block (array of int32)
%  indices   byte displacement of each block (MPI_Aint_array)
%  oldtype   old datatype (MPI_Datatype)
%
%Output arguments:
%  newtype   new datatype (MPI_Datatype)
%  info      return code (int32)
%
% The MPI-2 standard deprecated this routine. This routine is replaced by 
%     MPI_Type_create_hindexed.
%
% SEE ALSO   mpi_Type_indexed, MPI_Type_create_struct, mpi_Type_free
%
% C interface:
% int MPI_Type_hindexed(int count, int blocklens[], MPI_Aint indices[], ...
%     MPI_Datatype oldtype, MPI_Datatype *newtype);
% http://mpi.deino.net/mpi_functions/MPI_Type_hindexed.html

%#codegen -args {int32(0), coder.typeof(int32(0),[inf,1]), MPI_Aint_array, MPI_Datatype}


coder.inline('never');

info = int32(0);
newtype0 = coder.opaque('MPI_Datatype');
dtype = MPI_Datatype(oldtype);

indices0 = MPI_Aint_array(indices);
info = coder.ceval('MPI_Type_hindexed', int32(count), coder.rref(blocklens), ...
    m2c_opaque_ptr_const(indices0, 'MPI_Aint *'), dtype, coder.wref(newtype0));

toplevel = nargout>2;
newtype = MPI_Datatype(newtype0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_hindexed returned error code %d\n', info)
end


function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! var2 = zeros(10,10);

%! blocklens = [int32(5); int32(5)];
%! indices = MPI_Aint_array(2);
%! indices = MPI_Aint_array(indices, 'set', 1, MPI_Aint(0));
%! indices = MPI_Aint_array(indices, 'set', 2, MPI_Aint(40));

%! newtype = mpi_Type_hindexed(int32(2), blocklens, indices, MPI_DOUBLE);
%! newtype = mpi_Type_commit(newtype);

%! count = int32(10);
%! [req,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, newtype, int32(0), int32(1), comm);
%! assert(info==0);
%! info = mpi_Send(m2c_opaque_ptr_const(var1), count, newtype, int32(0), int32(1), comm);
%! assert(info==0);
%! mpi_Request_free(req);
%! assert(isequal(var1, var2));

%! mpi_Type_free(newtype);
