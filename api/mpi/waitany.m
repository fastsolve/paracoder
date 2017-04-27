function [idx, stat, reqs, info] = waitany(reqs)
%waitany   Waits for any specified send or receive to complete.
%
%  [idx, stat, reqs, info] = waitany(reqs)
%
%Input arguments:
%  reqs   communication requests (see MPI_Request_array)
%Output arguments:
%  idx   the index of the completed request object (zero-based)
%  stat  An MPI_Status object
%  reqs   If an communication object associated with the completed request 
%      was created by a nonblocking send or receive call, then the object 
%      is deallocated by the call,  and the request handle is set to 
%      MPI_REQUEST_NULL.
%  info (int)	return code
%
%  SEE ALSO: wait, waitall
%
%  If all of the requests are MPI_REQUEST_NULL, then idx is returned as
%  MPI_UNDEFINED, and stat is returned as an empty status

coder.inline('always');

if isstruct(reqs)
    count = reqs.nitems;
else
    assert(isa(reqs, 'uint8'));
    count = int32(length(reqs)) / mpi_get_sizeof('MPI_Request');
end

if nargout>1
    [idx, stat, reqs, info] = mpi_Waitany(count, reqs);
else
    idx = mpi_Waitany(count, reqs);
end

function test  %#ok<DEFNU>
%!test
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! count = int32(numel(var1));
%! var2 = zeros(10,10);
%!
%! [var2, req1, info] = irecv(var2, int32(0), int32(1), comm);
%! assert(info==0);
%! [req2,info] = isend(var1, int32(0), int32(1), comm);
%! assert(info==0);
%!
%! reqs = MPI_Request_array(2);
%! reqs.data = [req1.data; req2.data];

%! [idx1, stat, reqs, info] = waitany(reqs); assert(info==0);
%! assert(isequal(MPI_Request_array(reqs,'get',idx1+1), MPI_REQUEST_NULL));
%! assert(idx1 || MPI_Status(stat, 'get', 'source')==0 && MPI_Status(stat, 'get', 'tag')==1);

%! [idx2, stat, reqs, info] = waitany(reqs); assert(info==0);
%! assert(isequal(MPI_Request_array(reqs,'get',idx2+1), MPI_REQUEST_NULL));
%! assert(idx2 || MPI_Status(stat, 'get', 'source')==0 && MPI_Status(stat, 'get', 'tag')==1);
%! 
%! assert(idx1+idx2==1);
%! assert(isequal(var1, var2));
