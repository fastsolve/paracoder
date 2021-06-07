function [stat, info, toplevel] = mpi_Sendrecv_replace (ptr, count, datatype, dst, stag, ...
    src, rtag, comm)
%mpi_Sendrecv_replace  Sends and receives using a single buffer
%
%  [status, info] = mpi_Sendrecv_replace(ptr, count, datatype, dest, stag, 
%      src, rtag, comm)
%
%  Input Parameters
%  ptr        An m2c_opaque_ptr to MATLAB variable to be sent
%  count      number of elements in buffer (integer)
%  datatype   type of elements in buffer
%  dest       rank of destination (integer)
%  sendtag    send tag (integer)
%  source     rank of source (integer)
%  recvtag    receive tag (integer)
%  comm       communicator (handle)
%
%  Output Parameters
%  status     object (Status). This refers to the receive operation.
%  info       return code
%
%  SEE ALSO: mpi_Sendrecv
%
% C interface:
% int MPI_Sendrecv_replace(void *buf, int count, MPI_Datatype datatype, 
%                        int dest, int sendtag, int source, int recvtag,
%                        MPI_Comm comm, MPI_Status *status)
% http://mpi.deino.net/mpi_functions/MPI_Sendrecv.html

%#codegen -args {m2c_opaque_ptr, int32(0), MPI_Datatype, int32(0), int32(0),
%#codegen int32(0), int32(0), MPI_Comm}

info = int32(0); %#ok<NASGU>

if isstruct(ptr) && coder.target('MATLAB')
    if (ptr.nbytes-ptr.offset < count*mpi_Type_size(datatype))
        m2c_error('mpi_Sendrecv_replace:OutOfBound','Message size is larger than variable size.');
    end
end

stat0 = coder.opaque('MPI_Status');
info = coder.ceval('MPI_Sendrecv_replace', m2c_opaque_ptr(ptr), int32(count), ...
    MPI_Datatype(datatype), int32(dst), int32(stag), ...
    int32(src), int32(rtag), MPI_Comm(comm), coder.wref(stat0));

toplevel = nargout>2;
stat = MPI_Status(stat0, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Sendrecv_replace failed with error message %s\n', mpi_Error_string(info))
end

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! count = int32(numel(var1));
%!
%! [stat,info] = mpi_Sendrecv_replace(m2c_opaque_ptr(var1), count, MPI_DOUBLE, ...
%!        int32(0), int32(1), int32(0), int32(1), comm);
%! assert(MPI_Status(stat, 'get', 'source')==0 && MPI_Status(stat, 'get', 'tag')==1);
%! assert(info==0);
