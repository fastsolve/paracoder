function [info, toplevel] = mpi_Ssend(ptr, count, datatype, dest, tag, comm)
%mpi_Srsend  Blocking synchronous send
%
%  info = mpi_Srsend(ptr, count, datatype, dest, tag, comm)
%
%  ptr        an m2c_opaque_ptr_const to a variable.
%  count      number of data items
%  datatype   an opaque MPI_Datatype object (see MPI_Datatype)
%  src        rank of source
%  tag        message tag
%  comm       MPI_Comm object (see MPI_Comm)
%
%  info (int) return code
%
%  SEE ALSO: mpi_Send, mpi_Recv
%
%  This  function will not complete until the destination rank starts to
%  receive the message. Note that this is different than saying that the
%  message has been received by the destination rank.
%
% C interface:
%   int MPI_Ssend(void *buf, int count, MPI_Datatype datatype, int dest, int tag,
%                MPI_Comm comm)
% http://mpi.deino.net/mpi_functions/MPI_Ssend.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype, int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(ptr) && coder.target('MATLAB')
    if (ptr.nbytes-ptr.offset < count*mpi_Type_size(datatype))
        m2c_error('mpi_Ssend:OutOfBound','Message size is larger than variable size.');
    end
end

info = coder.ceval('MPI_Ssend', m2c_opaque_ptr_const(ptr), int32(count), ...
    MPI_Datatype(datatype), int32(dest), int32(tag), MPI_Comm(comm));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Ssend error code %d\n', info)
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
