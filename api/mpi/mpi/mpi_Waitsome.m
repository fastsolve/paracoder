function [idxs, stats, reqs, info, toplevel] = mpi_Waitsome (count, reqs)
%mpi_Waitsome	Waits for some given communications to complete
%
%  [idxs, stats, reqs, info] = mpi_Waitsome (count, reqs)
%
%  count:  number of communications
%  reqs: (INOUT) communication requests. If the communication object
%      associated with the completed request was created by a nonblocking
%      send or receive call, then the object is deallocated by the call,
%      and the request handle is set to MPI_REQUEST_NULL.
%
%  idxs:   array of indices of operations that have completed
%  stats:  array of MPI_Status objects
%  info:   return code (int)
%
%  SEE ALSO: mpi_Test, mpi_Testall, mpi_Testany, mpi_Testsome,
%     mpi_Wait, mpi_Wait_all, mpi_Wait_any, mpi_Start, mpi_Startall
%
%  The array of indexes are in the range 0 to incount-1.
%  Null requests are ignored. If all requests are null, then the routine
%  returns with count set to MPI_UNDEFINED.
%
% C interface:
%   int MPI_Waitsome(int incount, MPI_Request array_of_requests[],
%                    int *outcount, int array_of_indices[],
%                    MPI_Status array_of_statuses[])
% http://mpi.deino.net/mpi_functions/MPI_Waitsome.html

%#codegen -args {int32(0), MPI_Request_array}

% This function should not be inlined, because of the handling of arrays.
coder.inline('never');

if isstruct(reqs) && coder.ismatlabthread
    if length(reqs.data) < count*mpi_get_sizeof('MPI_Request')
        m2c_error('mpi_Waitsome:OutOfBound', 'MPI_Request array is too small.');
    end
end

info = int32(0); %#ok<NASGU>
idxs = zeros(count,1,'int32');
n = int32(0);
reqs0 = MPI_Request_array(reqs);

if nargout>1
    stats0 = MPI_Status_array(count);
    [reqs0,stats0] = m2c_unalias(reqs0,stats0);
    info = coder.ceval('MPI_Waitsome', int32(count), ...
        m2c_opaque_ptr(reqs0, 'MPI_Request *'), ...
        coder.wref(n), coder.ref(idxs), m2c_opaque_ptr(stats0, 'MPI_Status *'));

    toplevel = nargout>4;
    reqs = MPI_Request_array(reqs0, count, toplevel);
    stats = MPI_Status_array(stats0, count, toplevel);
    
    if info && (toplevel || m2c_debug)
        m2c_error('MPI:RuntimeError', 'MPI_Waitsome failed with error message %s\n', mpi_Error_string(info))
    end
else
    reqs0 = m2c_unalias(reqs0);
    info = coder.ceval('MPI_Waitsome', int32(count), ...
        m2c_opaque_ptr(reqs0, 'MPI_Request *'), coder.wref(n), ...
        coder.ref(idxs), coder.opaque('MPI_Status *', 'MPI_STATUSES_IGNORE'));
    m2c_rref(reqs0);
end
idxs = idxs(1:n);

function test  %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! count = int32(numel(var1));
%! var2 = zeros(10,10);
%!
%! [req1,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! [req2,info] = mpi_Isend(m2c_opaque_ptr_const(var1), count, MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! reqs = MPI_Request_array(2);
%! reqs = MPI_Request_array(reqs, 'set', 1, req1);
%! reqs = MPI_Request_array(reqs, 'set', 2, req2);

%! [idxs, stats, reqs, info] = mpi_Waitsome(int32(2), reqs);
%! assert(info==0);
%! assert(isequal(MPI_Request_array(reqs, 'get', 1), MPI_REQUEST_NULL));
%! assert(isequal(MPI_Request_array(reqs, 'get', 2), MPI_REQUEST_NULL));
%! assert(MPI_Status_array(stats, 'get', 1, 'source')==0 && ...
%!        MPI_Status_array(stats, 'get', 1, 'tag')==1);

%! assert(isequal(var1, var2));
