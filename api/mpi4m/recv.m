function [rbuf, status, info] = recv(rbuf, src, tag, comm) %#codegen
%RECV Performs a blocking receive on a whole array
%   [rbuf, status, info] = recv(rbuf, src, tag, comm)
%
%Input arguments:
%  rbuf    a variable corresponding to a buffer (an array)
%  src     rank of source process (int32)
%  tag     message tag (int32)
%  comm    MPI_Comm object (see MPI_Comm)
%
%Output arguments:
%  rbuf    the receive buffer
%  req     returned communication request (see MPI_Request)
%  info    return code (int32)
%
% It is recommended that rbuf is a variable or a field in a structure 
% in the calling function. To receive on a subset of an array, use recv_sub 
% to avoid unnecessary buffer copying.
%
%See also recv_sub, irecv, send, isend

coder.inline('always');

rbuf = m2c_unalias(rbuf);
[status, info] = mpi_Recv(m2c_opaque_ptr(rbuf), int32(numel(rbuf)), ...
    MPI_Datatype(rbuf), int32(src), int32(tag), MPI_Comm(comm));
