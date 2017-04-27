function [stat, info, toplevel] = mpi_Recv(ptr, count, datatype, src, tag, comm)
%mpi_Recv    Blocking receive for a message
%
%  [status, info] = mpi_Recv(ptr, count, datatype, src, tag, comm)
%
%  ptr        an m2c_opaque_ptr to a variable
%  count      number of data items
%  datatype   an opaque MPI_Datatype object (see MPI_Datatype)
%  src        rank of source
%  tag        message tag
%  comm       MPI_Comm object (see MPI_Comm)
%
%  status     status object (Status)
%
%  info (int) return code
%
%  SEE ALSO: mpi_Send, mpi_Probe, mpi_Iprobe, mpi_Irecv, mpi_Recv_init
%
% C interface:
%   int MPI_Recv(void *buf, int count, MPI_Datatype datatype, int source, int tag,
%                MPI_Comm comm, MPI_Status *status)
% http://mpi.deino.net/mpi_functions/MPI_Recv.html

%#codegen -args {m2c_opaque_ptr, int32(0), MPI_Datatype, int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(ptr) && coder.ismatlabthread
    if (ptr.nbytes-ptr.offset < count*mpi_Type_size(datatype))
        m2c_error('mpi_Recv:OutOfBound','Message size is larger than variable size.');
    end
end

stat0 = coder.opaque('MPI_Status');
info = coder.ceval('MPI_Recv', m2c_opaque_ptr(ptr), int32(count), MPI_Datatype(datatype), ...
    int32(src), int32(tag), MPI_Comm(comm), coder.wref(stat0));

toplevel = nargout>2;
stat = MPI_Status(stat0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Recv failed with error message %s\n', mpi_Error_string(info))
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
%! ptr1 = m2c_opaque_ptr(var1);
%! [req, info] = mpi_Isend(ptr1, count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! ptr2 = m2c_opaque_ptr(var2);
%! [stat,info] = mpi_Recv(ptr2, count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(MPI_Status(stat, 'get', 'source')==0 && MPI_Status(stat, 'get', 'tag')==1);
%! mpi_Request_free(req);
%! assert(info==0);
%! assert(isequal(var1, var2));
