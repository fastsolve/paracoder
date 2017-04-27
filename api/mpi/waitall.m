function [stats, reqs, info] = waitall(reqs)
%waitall   Waits for all given communication requests to complete.
%
%  [stats, reqs, info] = waitall(reqs)
%
%Input arguments:
%  reqs   communication requests (see MPI_Request_array)
%Output arguments:
%  stats  MPI_Status_array object
%  reqs   If an communication object associated with the completed request 
%      was created by a nonblocking send or receive call, then the object 
%      is deallocated by the call,  and the request handle is set to 
%      MPI_REQUEST_NULL.
%  info   return code (int32)
%
%  SEE ALSO: wait, waitall

coder.inline('always');

if isstruct(reqs)
    count = reqs.nitems;
else
    assert(isa(reqs, 'uint8'));
    count = int32(length(reqs)) / mpi_get_sizeof('MPI_Request');
end

if nargout>0
    [stats, reqs, info] = mpi_Waitall(count, reqs);
else
    mpi_Waitall(count, reqs);
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

%! reqs = MPI_Request_array(2);
%! reqs = MPI_Request_array(reqs, 'set', 1, req1);
%! reqs = MPI_Request_array(reqs, 'set', 2, req2);

%! [stats, reqs, info] = waitall(reqs); assert(info==0);
%! assert(isequal(MPI_Request_array(reqs, 'get', 1), MPI_REQUEST_NULL));
%! assert(isequal(MPI_Request_array(reqs, 'get', 2), MPI_REQUEST_NULL));
%! assert(MPI_Status_array(stats, 'get', 1, 'source')==0 && ...
%!        MPI_Status_array(stats, 'get', 1, 'tag')==1);

%! assert(isequal(var1, var2));
