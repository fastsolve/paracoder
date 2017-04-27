function info = send_sub(sbuf, start, count, type, dst, tag, comm) %#codegen
%SEND_SUB Performs a blocking send on a subset of an array.
%   info = send_sub(sbuf, start, count, type, dst, tag, comm)
%
%Input arguments:
%  sbuf    a variable corresponding to a buffer (an array)
%  start   the starting index in sbuf (int32)
%  count   number of data items (int32)
%  type    data type (MPI_Datatype). If empty, it is set to MPI_Datatype(sbuf).
%  dst     rank of destination process (int32)
%  tag     message tag (int32)
%  comm    MPI_Comm object (see MPI_Comm)
%
%Output arguments:
%  info    return code (int32)
%
%SEE ALSO send, isend, recv, irecv

coder.inline('always');

if start<=0 || start+count-1>numel(sbuf)
    m2c_error('The specified range is beyond the send buffer.');
end

offset = int32(start-1) * mpi_Type_size(MPI_Datatype(sbuf));
if isempty(type)
    info = mpi_Send(m2c_opaque_ptr_const(sbuf, 'char *', offset), ...
        int32(count), MPI_Datatype(sbuf), int32(dst), int32(tag), MPI_Comm(comm));
else
    info = mpi_Send(m2c_opaque_ptr_const(sbuf, 'char *', offset), ...
        int32(count), type, int32(dst), int32(tag), MPI_Comm(comm));
end