function [req, info, toplevel] = mpi_Irecv(ptr, count, datatype, src, tag, comm)
%mpi_Irecv    Begins a nonblocking receive.
%
%  [req, info] = mpi_Irecv(ptr, count, datatype, src, tag, comm)
%
%Input arguments:
%  ptr        an m2c_opaque_ptr_const to a variable with or without offset.
%  count      number of data items
%  datatype   an opaque MPI_Datatype object (see MPI_Datatype)
%  src        rank of source process
%  tag        message tag
%  comm       MPI_Comm object (see MPI_Comm)
%
%Output arguments:
%  req        returned communication request (handle)
%  info (int) return code
%
% It is critical that ptr corresponds to a variable or a field of a
% structure wrapped by m2c_opaque_ptr.
%
% The communication started with this function is not guaranteed to progress
% or complete until req has been given to one of the test or wait functions.
% The caller should not access the receive buffer until the communication 
% completes.
%
%  SEE ALSO: mpi_Recv, mpi_Test, mpi_Testall, mpi_Testany, 
%            mpi_Testsome, mpi_Wait, mpi_Wait_any, mpi_Wait_some
%
% C interface:
% int MPI_Irecv(void *buf, int count, MPI_Datatype datatype, int src, int tag,
%              MPI_Comm comm, MPI_Request *request)
% http://mpi.deino.net/mpi_functions/MPI_Irecv.html

%#codegen -args {m2c_opaque_ptr, int32(0), MPI_Datatype, int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(ptr) && coder.ismatlabthread && ...
        (ptr.nbytes-ptr.offset < count*mpi_Type_size(datatype))
    m2c_error('mpi_Irecv:OutOfBound','Message size is larger than variable size.');
end

req0 = coder.opaque('MPI_Request');
info = coder.ceval('MPI_Irecv', m2c_opaque_ptr(ptr), int32(count), MPI_Datatype(datatype), ...
    int32(src), int32(tag), MPI_Comm(comm), coder.wref(req0));

toplevel = nargout>2;
req = MPI_Request(req0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Irecv failed with error message %s\n', mpi_Error_string(info))
end


function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! count = int32(numel(var1));
%! var2 = zeros(10,10);
%!
%! [req,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! info = mpi_Send(m2c_opaque_ptr_const(var1), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! mpi_Wait(req);
%! assert(info==0);
%! assert(isequal(var1, var2));
