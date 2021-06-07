function [req, info, toplevel] = mpi_Rsend_init(ptr, count, datatype, dest, tag, comm)
%mpi_Rsend_init   Creates a persistent request for a ready send
%
%  [req, info] = mpi_Rsend_init(ptr, count, datatype, dest, tag, comm)
%
%  ptr        an m2c_opaque_ptr_const to a variable.
%  count      number of data items
%  datatype   an opaque MPI_Datatype object (see MPI_Datatype)
%  src        rank of source
%  tag        message tag
%  comm       MPI_Comm object (see MPI_Comm)
%
%  req        communication request (handle)
%
%  info (int) return code
%
%  SEE ALSO: mpi_Start, mpi_Startall, mpi_Test, mpi_Testall,
%      mpi_Testany, mpi_Testsome, mpi_Wait, mpi_Waitall, mpi_Waitany,
%      mpi_Waitsome, mpi_Rsend
%
% C interface:
%   int MPI_Rsend_init(void *buf, int count, MPI_Datatype datatype, int dest,
%                      int tag, MPI_Comm comm, MPI_Request *request)
% http://mpi.deino.net/mpi_functions/MPI_Rsend_init.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype, int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(ptr) && coder.target('MATLAB')
    if (ptr.nbytes-ptr.offset < count*mpi_Type_size(datatype))
        m2c_error('mpi_Rsend_init:OutOfBound','Message size is larger than variable size.');
    end
end

req0 = coder.opaque('MPI_Request');
info = coder.ceval('MPI_Rsend_init', m2c_opaque_ptr_const(ptr), int32(count), ...
    MPI_Datatype(datatype), int32(dest), int32(tag), MPI_Comm(comm), coder.wref(req0));

toplevel = nargout>2;
req = MPI_Request(req0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Rsend_init failed with error message %s\n', mpi_Error_string(info))
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
%! [req1, info] = mpi_Irecv(m2c_opaque_ptr(var2), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! [req2, info] = mpi_Rsend_init(m2c_opaque_ptr_const(var1), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! info = mpi_Start(req2);
%! mpi_Wait(req1);
%! mpi_Request_free(req2);

%! assert(info==0);
%! assert(isequal(var1, var2));
