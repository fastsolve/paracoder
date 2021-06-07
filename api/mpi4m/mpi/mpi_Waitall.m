function [stats, reqs, info, toplevel] = mpi_Waitall(count, reqs)
%mpi_Waitall  Waits for all given communication requests to complete.
%
%  [stats, reqs, info] = mpi_Waitall(count, reqs)
%
%  count: number of communication requests
%  reqs (INOUT): communication requests. If the communication object
%      associated with the completed request was created by a nonblocking
%      send or receive call, then the object is deallocated by the call,
%      and the request handle is set to MPI_REQUEST_NULL.
%  
%  stats: MPI_Status_array object
%  info (int) return code
%
%  SEE ALSO: mpi_Test, mpi_Testall, mpi_Testany, mpi_Testsome,
%     mpi_Wait, mpi_Wait_any, mpi_Waitsome, mpi_Start, mpi_Startall
%
% C interface:
%   int MPI_Waitall(int count, MPI_Request array_of_requests[],
%                   MPI_Status array_of_statuses[])
% http://mpi.deino.net/mpi_functions/MPI_Waitall.html

%#codegen -args {int32(0), MPI_Request_array}


% This function should not be inlined, because of the handling of arrays.
coder.inline('never');

if isstruct(reqs) && coder.target('MATLAB')
    if length(reqs.data) < count*mpi_get_sizeof('MPI_Request')
        m2c_error('mpi_Waitall:OutOfBound', 'MPI_Request_array is too small.');
    end
end

info = int32(0); %#ok<NASGU>
reqs0 = MPI_Request_array(reqs);

if nargout>0
    stats0 = MPI_Status_array(count);
    [reqs0,stats0] = m2c_unalias(reqs0,stats0);
    info = coder.ceval('MPI_Waitall', int32(count), ...
        m2c_opaque_ptr(reqs0, 'MPI_Request *'), ...
        m2c_opaque_ptr(stats0, 'MPI_Status *'));
    
    toplevel = nargout>3;
    reqs = MPI_Request_array(reqs0, count, toplevel);
    stats = MPI_Status_array(stats0, count, toplevel);
    
    if info && (toplevel || m2c_debug)
        m2c_error('MPI:RuntimeError', 'MPI_Waitall failed with error message %s\n', mpi_Error_string(info))
    end
else
    reqs0 = m2c_unalias(reqs0);
    info = coder.ceval('MPI_Waitall', int32(count), ...
        m2c_opaque_ptr(reqs0, 'MPI_Request *'), ...
        coder.opaque('MPI_Status *','MPI_STATUSES_IGNORE'));
    m2c_rref(reqs0);
end

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

%! [stats, reqs, info] = mpi_Waitall(int32(2), reqs); assert(info==0);
%! assert(isequal(MPI_Request_array(reqs, 'get', 1), MPI_REQUEST_NULL));
%! assert(isequal(MPI_Request_array(reqs, 'get', 2), MPI_REQUEST_NULL));
%! assert(MPI_Status_array(stats, 'get', 1, 'source')==0 && ...
%!        MPI_Status_array(stats, 'get', 1, 'tag')==1);

%! assert(isequal(var1, var2));
