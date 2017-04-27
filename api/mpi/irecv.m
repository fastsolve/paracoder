function [rbuf, req, info] = irecv(rbuf, src, tag, comm) %#codegen
%IRECV   Starts a non-blocking receive on a whole array
%   [rbuf, req, info] = irecv(rbuf, src, tag, comm)
%
%Input arguments:
%  rbuf    a variable corresponding to a buffer (an array)
%  src     rank of source process (int32)
%  tag     message tag (int32)
%  comm    MPI_Comm object (see MPI_Comm)
%
%Output arguments:
%  rbuf    the rbuf is not ready until the communication completes.
%  req     returned communication request (see MPI_Request)
%  info    return code (int32)
%
% It is important that rbuf is a variable in the calling function.
% It cannot be a subset of an array or a a field in a structure. 
% To send a subset of an array, use irecv_sub instead.
%
% The communication started with this function is not guaranteed to progress
% or complete until req has been given to one of the test or wait functions.
%
%SEE ALSO irecv_sub, isend, isend_sub, recv, send, wait, waitany, waitall

coder.inline('always');

if isempty(coder.target) && isempty(inputname(1))
    m2c_error(['The first input argument to irecv must be a simple variable ' ...
        'corresponding to a whole array. It cannot be any other expression. '  ...
        'Fix it by passing in a complete array or using irecv_sub.']);
end

rbuf = m2c_unalias(rbuf);
[req, info] = mpi_Irecv(m2c_opaque_ptr(rbuf), int32(numel(rbuf)), ...
    MPI_Datatype(rbuf), int32(src), int32(tag), MPI_Comm(comm));
