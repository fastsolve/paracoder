function info = send(sbuf, dst, tag, comm) %#codegen
%SEND Performs a blocking send on a whole array.
%   info = send(sbuf, dst, tag, comm)
%
%Input arguments:
%  sbuf    a variable corresponding to a buffer (an array)
%  dst     rank of destination process (int32)
%  tag     message tag (int32)
%  comm    MPI_Comm object (see MPI_Comm)
%
%Output arguments:
%  info    return code (int32)
%
% It is recommended that sbuf is a variable or a field in a structure 
% in the calling function. To send a subset of an array, use send_sub 
% to avoid unnecessary buffer copying.
%
%SEE ALSO send_sub, isend, recv, irecv

coder.inline('always');

info = mpi_Send(m2c_opaque_ptr_const(sbuf), int32(numel(sbuf)), ...
    MPI_Datatype(sbuf), int32(dst), int32(tag), MPI_Comm(comm));
