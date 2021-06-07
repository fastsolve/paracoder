function [stat, info, toplevel] = mpi_Sendrecv(sptr, scount, stype, dst, stag, ...
    rptr, rcount, rtype, src, rtag, comm)
%mpi_Sendrecv	Sends and receives a message
%
%  [status, info] = mpi_Sendrecv (sptr, scount, stype, dest, stag, 
%      rptr, rcount, rtype, src, rtag, comm)
%
%  Input Parameters
%  sptr       An m2c_opaque_ptr_const to MATLAB variable to be sent
%  sendcount  number of elements in send buffer (integer)
%  sendtype   type of elements in send buffer (handle)
%  dest       rank of destination (integer)
%  sendtag    send tag (integer)
%  rptr       An m2c_opaque_ptr to MATLAB variable to be received
%  recvcount  number of elements in receive buffer (integer)
%  recvtype   type of elements in receive buffer (handle)
%  source     rank of source (integer)
%  recvtag    receive tag (integer)
%  comm       communicator (handle)
%
%  Output Parameters
%  status     object (Status). This refers to the receive operation.
%  info       return code
%
%  SEE ALSO: mpi_Sendrecv_replace
%
% C interface:
% int MPI_Sendrecv(void *sendbuf, int sendcount, MPI_Datatype sendtype, 
%                 int dest, int sendtag,
%                 void *recvbuf, int recvcount, MPI_Datatype recvtype, 
%                 int source, int recvtag,
%                 MPI_Comm comm, MPI_Status *status)
% http://mpi.deino.net/mpi_functions/MPI_Sendrecv.html

%#codegen -args {m2c_opaque_ptr_const, int32(0), MPI_Datatype, int32(0), int32(0),
%#codegen m2c_opaque_ptr, int32(0), MPI_Datatype, int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(sptr) && coder.target('MATLAB')
    if (sptr.nbytes-sptr.offset < scount*mpi_Type_size(stype) || ...
            rptr.nbytes-rptr.offset < rcount*mpi_Type_size(rtype))
        m2c_error('mpi_Sendrecv:OutOfBound','Message size is larger than variable size.');
    end
end

stat0 = coder.opaque('MPI_Status');

info = coder.ceval('MPI_Sendrecv', m2c_opaque_ptr_const(sptr), int32(scount), ...
    MPI_Datatype(stype), int32(dst), int32(stag), ...
    m2c_opaque_ptr(rptr), int32(rcount), MPI_Datatype(rtype), ...
    int32(src), int32(rtag), MPI_Comm(comm), coder.wref(stat0));

toplevel = nargout>2;
stat = MPI_Status(stat0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Sendrecv failed with error message %s\n', mpi_Error_string(info))
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
%! [stat,info] = mpi_Sendrecv(m2c_opaque_ptr(var1), count, MPI_DOUBLE, int32(0), int32(1), ...
%!        m2c_opaque_ptr(var2), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(MPI_Status(stat, 'get', 'source')==0 && MPI_Status(stat, 'get', 'tag')==1);
%! assert(info==0);
%! assert(isequal(var1, var2));
