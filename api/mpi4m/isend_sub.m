function [req, info] = isend_sub(sbuf, start, count, type, dst, tag, comm) %#codegen
%ISEND_SUB  Starts a nonblocking send on a subset of an array
%   [req, info] = isend_sub(sbuf, start, type, count, dst, tag, comm)
%
%Input arguments:
%  sbuf    a variable corresponding to a buffer (an array)
%  start   the starting index in sbuf (int32)
%  count   number of data items in the given datatype (int32)
%  type    data type (MPI_Datatype). If empty, it is set to MPI_Datatype(sbuf).
%  dst     rank of destination process (int32)
%  tag     message tag (int32)
%  comm    MPI_Comm object (see MPI_Comm)
%
%Output arguments:
%  req     returned communication request (see MPI_Request)
%  info    return code (int32)
%
% It is important that sbuf is a variable or a field in a structure.
% in the calling function.
%
% The communication started with this function is not guaranteed to progress
% or complete until req has been given to one of the test or wait functions.
% The caller must not modify the send buffer until the communication completes.
%
%SEE ALSO isend, send, irecv, irecv_sub, recv, wait, waitany, waitall

coder.inline('always');

if start<=0 || start+count-1>numel(sbuf)
    m2c_error('The specified range is beyond the send buffer.');
end

offset = int32(start-1) * mpi_Type_size(MPI_Datatype(sbuf));
if isempty(type)
    [req, info] = mpi_Isend(m2c_opaque_ptr_const(sbuf, 'char *', offset), ...
        int32(count), MPI_Datatype(sbuf), int32(dst), int32(tag), MPI_Comm(comm));
else
    [req, info] = mpi_Isend(m2c_opaque_ptr_const(sbuf, 'char *', offset), ...
        int32(count), type, int32(dst), int32(tag), MPI_Comm(comm));
end

function test  %#ok<DEFNU>
%!test
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! count = int32(numel(var1));
%! var2 = zeros(10,10);
%!
%! var2 = irecv_init(var2);
%! [req1, info] = irecv_sub(var2, 1, 50, [], 0, 1, comm);
%! [req2, info] = irecv_sub(var2, 51, 50, MPI_DOUBLE, 0, 1, comm);
%!
%! assert(info==0);

%! [req3, info] = isend_sub(var1, 1, 50, [], 0, 1, comm);
%! [req4, info] = isend_sub(var1, 51, 50, MPI_DOUBLE, 0, 1, comm);

%! reqs = MPI_Request_array(4);
%! reqs.data = [req1.data; req2.data; req3.data; req4.data];

%! for i=1:4; [idx, stat, reqs, info] = waitany(reqs); end
%! assert(isequal(var1, var2));
