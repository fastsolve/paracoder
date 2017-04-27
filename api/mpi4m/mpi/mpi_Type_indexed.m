function [newtype, info, toplevel] = mpi_Type_indexed(count, blocklens, indices, oldtype)
%mpi_Type_indexed   Creates an indexed datatype
%
%  [newtype, info] = mpi_Type_indexed(count, blocklens, indices, oldtype)
%
%Input arguments:
%  count     number of blocks and number of entries in blocklens & indices(int32)
%  blocklens number of elements in each block (array of int32)
%  indices   displacement of each block in multiples of oldtype (array of int32)
%  oldtype   old datatype (MPI_Datatype)
%
%Output arguments:
%  newtype   new datatype (MPI_Datatype)
%  info      return code (int32)
%
% SEE ALSO   mpi_Type_hindexed, mpi_Type_free
%
% C interface:
% int MPI_Type_indexed(int count, int blocklens[], int indices[], MPI_Datatype oldtype, MPI_Datatype *newtype)
% http://mpi.deino.net/mpi_functions/MPI_Type_indexed.html

%#codegen -args {int32(0), coder.typeof(int32(0),[inf,1]), coder.typeof(int32(0),[inf,1]), MPI_Datatype}

    
info = int32(0); %#ok<NASGU>
newtype0 = coder.opaque('MPI_Datatype');

if length(blocklens)<count && length(indices)<count
    m2c_error('The specified blocklens or indices are too small.');
end

info = coder.ceval('MPI_Type_indexed', int32(count), coder.rref(blocklens), ...
    coder.rref(indices), MPI_Datatype(oldtype), coder.wref(newtype0));

toplevel = nargout>2;
newtype = MPI_Datatype(newtype0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Type_hvector failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! var2 = zeros(10,10);

%! blocklens = [int32(5); int32(5)];
%! indices = [int32(0); int32(5)];

%! newtype = mpi_Type_indexed(int32(2), blocklens, indices, MPI_DOUBLE);
%! newtype = mpi_Type_commit(newtype);

%! count = int32(10);
%! [req,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, newtype, int32(0), int32(1), comm);
%! assert(info==0);
%! info = mpi_Send(m2c_opaque_ptr_const(var1), count, newtype, int32(0), int32(1), comm);
%! assert(info==0);
%! mpi_Request_free(req);
%! assert(isequal(var1, var2));

%! mpi_Type_free(newtype);
