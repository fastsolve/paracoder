function [newtype, info, toplevel] = mpi_Type_create_struct(count, blocklens, indices, oldtypes)
%mpi_Type_create_struct   Creates a struct datatype
%
%  [newtype, info] = mpi_Type_create_struct(count, blocklens, indices, oldtypes)
%
%Input arguments:
%  count     number of blocks and number of entries in blocklens & indices(int32)
%  blocklens number of elements in each block (array of int32)
%  indices   byte displacement of each block (MPI_Aint_array)
%  oldtypes  datatype of elements in each block (MPI_Datatype_array)
%
%Output arguments:
%  newtype   new datatype (MPI_Datatype)
%  info      return code (int32)
%
% SEE ALSO   mpi_Type_indexed, MPI_Type_create_hindexed, mpi_Type_free
%
% C interface:
% int MPI_Type_create_struct(int count, int blocklens[], MPI_Aint indices[],
%     MPI_Datatype oldtype[], MPI_Datatype *newtype);
% http://mpi.deino.net/mpi_functions/MPI_Type_create_struct.html

%#codegen -args {int32(0), coder.typeof(int32(0),[inf,1]), MPI_Aint_array, MPI_Datatype_array}


info = int32(0); %#ok<NASGU>
newtype0 = coder.opaque('MPI_Datatype');

indices0 = MPI_Aint_array(indices);
oldtypes0 = MPI_Datatype_array(oldtypes);

[indices0,oldtypes0] = m2c_unalias(indices0,oldtypes0);
info = coder.ceval('MPI_Type_create_struct', int32(count), coder.rref(blocklens), ...
    m2c_opaque_ptr_const(indices0, 'MPI_Aint *'), ...
    m2c_opaque_ptr_const(oldtypes0, 'MPI_Datatype *'), coder.wref(newtype0));
m2c_rref(indices0,oldtypes0); %#ok<NASGU>

toplevel = nargout>2;
newtype = MPI_Datatype(newtype0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_create_struct failed with error message %s\n', mpi_Error_string(info))
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

%! oldtype = MPI_Datatype_array(2);
%! oldtype = MPI_Datatype_array(oldtype, 'set', 1, MPI_DOUBLE);
%! oldtype = MPI_Datatype_array(oldtype, 'set', 2, MPI_DOUBLE);

%! newtype = mpi_Type_create_struct(int32(2), blocklens, indices, oldtype);
%! newtype = mpi_Type_commit(newtype);

%! count = int32(10);
%! [req,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, newtype, int32(0), int32(1), comm);
%! assert(info==0);
%! info = mpi_Send(m2c_opaque_ptr_const(var1), count, newtype, int32(0), int32(1), comm);
%! assert(info==0);
%! mpi_Request_free(req);
%! assert(isequal(var1, var2));

%! mpi_Type_free(newtype);
