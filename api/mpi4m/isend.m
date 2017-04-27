function [req, info] = isend(sbuf, dst, tag, comm) %#codegen
%ISEND Begins a nonblocking send on a whole array.
%   [req, info] = isend(sbuf, dst, tag, comm)
%
%Input arguments:
%  sbuf    a variable corresponding to a buffer (an array)
%  dst     rank of destination process (int32)
%  tag     message tag (int32)
%  comm    MPI_Comm object (see MPI_Comm)
%
%Output arguments:
%  req     returned communication request (see MPI_Request)
%  info    return code (int32)
%
% It is important that sbuf is a variable in the calling function.
% It cannot be a subset of an array or a a field in a structure. 
% To send a subset of an array, use isend_sub instead.
%
% The communication started with this function is not guaranteed to progress
% or complete until req has been given to one of the test or wait functions.
% The caller must not modify the send buffer until the communication completes.
%
%SEE ALSO isend_sub, send, irecv, irecv_sub, recv, wait, waitany, waitall

coder.inline('always');

if isempty(coder.target) && isempty(inputname(1))
    m2c_error(['The first input argument to isend must be a simple variable ' ...
        'corresponding to a whole array. It cannot be any other expression. '  ...
        'Fix it by passing in a complete array or using isend_sub.']);
end

[req, info] = mpi_Isend(m2c_opaque_ptr_const(sbuf), int32(numel(sbuf)), ...
    MPI_Datatype(sbuf), int32(dst), int32(tag), MPI_Comm(comm));
