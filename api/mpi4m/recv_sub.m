function [rbuf, status, info] = recv_sub(rbuf, start, count, type, src, tag, comm) %#codegen
%RECV_SUB Performs a blocking receive on a subset of an array
%   [rbuf, status, info] = recv_sub(rbuf, start, count, type, src, tag, comm)
%
%Input arguments:
%  rbuf    a variable corresponding to a buffer (an array)
%  start   the starting index in rbuf (int32)
%  count   number of data items (int32)
%  type    data type (MPI_Datatype). If empty, it is set to MPI_Datatype(sbuf).
%  src     rank of source process (int32)
%  tag     message tag (int32)
%  comm    MPI_Comm object (see MPI_Comm)
%
%Output arguments:
%  rbuf    the receive buffer
%  req     returned communication request (see MPI_Request)
%  info    return code (int32)
%
%See also recv, irecv, send, isend

coder.inline('always');

if start<=0 || start+count-1>numel(rbuf)
    m2c_error('The specified range is beyond the receive buffer.');
end

rbuf = m2c_unalias(rbuf);
offset = int32(start-1) * mpi_Type_size(MPI_Datatype(rbuf));
if isempty(type)
    [status, info] = mpi_Recv(m2c_opaque_ptr(rbuf, 'char *', offset), ...
        int32(count), MPI_Datatype(rbuf), int32(src), int32(tag), MPI_Comm(comm));
else
    [status, info] = mpi_Recv(m2c_opaque_ptr(rbuf, 'char *', offset), ...
        int32(count), type, int32(src), int32(tag), MPI_Comm(comm));
end
