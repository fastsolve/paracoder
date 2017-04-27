function [req,info, toplevel] = mpi_Ibsend(ptr, count, datatype, dest, tag, comm)
%mpi_Ibsend    Starts a nonblocking buffered send
%
%  [req,info] = mpi_Ibsend(ptr, count, datatype, dest, tag, comm)
%
%Input arguments:
%  ptr        an m2c_opaque_ptr_const to a variable with or without offset.
%  count      number of data items
%  datatype   an opaque MPI_Datatype object (see MPI_Datatype)
%  src        rank of source
%  tag        message tag
%  comm       MPI_Comm object (see MPI_Comm)
%
%Output arguments:
%  req        returned communication request (handle)
%  info (int) return code
%
% It is critical that ptr corresponds to a variable or a field of a
% structure wrapped by m2c_opaque_ptr_const.
%
% The communication started with this function is not guaranteed to progress
% or complete until req has been given to one of the test or wait functions.
% The caller must not modify the send buffer until the communication completes.
%
%  SEE ALSO: mpi_Bsend, mpi_Test, mpi_Testall, mpi_Testany, mpi_Testsome,
%      mpi_Wait, mpi_Waitall, mpi_Waitany, mpi_Waitsome
%
% C interface:
%    int MPI_Ibsend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
%                   MPI_Comm comm, MPI_Request *request)
% http://mpi.deino.net/mpi_functions/MPI_Ibsend.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype, int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

req0 = coder.opaque('MPI_Request');
info = coder.ceval('MPI_Ibsend', m2c_opaque_ptr_const(ptr), int32(count), ...
    MPI_Datatype(datatype), int32(dest), int32(tag), MPI_Comm(comm), ...
    coder.wref(req0));

toplevel = nargout>2;
req = MPI_Request(req0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Ibsend failed with error message %s\n', mpi_Error_string(info))
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
%! [req1,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! sz = count*8+MPI_BSEND_OVERHEAD;
%! buf = zeros(sz,1,'uint8');
%! mpi_Buffer_attach(m2c_opaque_ptr(buf), sz);
%! [req2, info] = mpi_Ibsend(m2c_opaque_ptr_const(var1), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! mpi_Wait(req1);
%! mpi_Wait(req2);
%! assert(isequal(var1, var2));
%! mpi_Buffer_detach;
