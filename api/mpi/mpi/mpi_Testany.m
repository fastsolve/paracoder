function [idx, flag, stat, reqs, info, toplevel] = mpi_Testany (count, reqs)
%mpi_Testany	Tests for completion of any previdously initiated requests
%
%  [idx, flag, stat, reqs, info] = mpi_Testany (count, reqs)
%
%  count        number of communications
%  reqs (INOUT) communication requests. If the communication object
%      associated with the completed request was created by a nonblocking
%      send or receive call, then the object is deallocated by the call,
%      and the request handle is set to MPI_REQUEST_NULL.
%
%  idx  (int)	index of operation that completed, or MPI_UNDEFINED if none
%  flag (int)	true if one of the operations is complete
%  stat is an MPI_Status object
%  info (int)	return code
%
%  SEE ALSO: mpi_Test, mpi_Testall, mpi_Testsome, mpi_Test, mpi_Wait,
%     mpi_Wait_all, mpi_Wait_any, mpi_Waitsome, mpi_Start, mpi_Startall
%
%  If all of the requests are MPI_REQUEST_NULL, then idx is returned as
%  MPI_UNDEFINED, and stat is returned as an empty status
%
% C interface:
%   int MPI_Testany(int count, MPI_Request array_of_requests[], int *index,
%                   int *flag, MPI_Status *status)
% http://mpi.deino.net/mpi_functions/MPI_Testany.html
% http://www.mpi-forum.org/docs/mpi-11-html/node49.html

%#codegen -args {int32(0), MPI_Request_array}

% This function should not be inlined, because of the handling of arrays.
coder.inline('never');

if isstruct(reqs) && coder.ismatlabthread
    if length(reqs.data) < count*mpi_get_sizeof('MPI_Request')
        m2c_error('mpi_Testall:OutOfBound', 'MPI_Request_array is too small.');
    end
end

info = int32(0); %#ok<NASGU>
flag = int32(0);
idx = int32(0);
reqs0 = MPI_Request_array(reqs);

if nargout>2
    stat0 = coder.opaque('MPI_Status');
    reqs0 = m2c_unalias(reqs0);
    info = coder.ceval('MPI_Testany', int32(count), ...
        m2c_opaque_ptr(reqs0, 'MPI_Request *'), ...
        coder.wref(idx), coder.wref(flag), coder.wref(stat0));

    toplevel = nargout>5;
    stat = MPI_Status(stat0, toplevel);
    reqs = MPI_Request_array(reqs0, count, toplevel);
    
    if info && (toplevel || m2c_debug)
        m2c_error('MPI:RuntimeError', 'MPI_Testany failed with error message %s\n', mpi_Error_string(info))
    end
else
    reqs0 = m2c_unalias(reqs0);
    info = coder.ceval('MPI_Testany', int32(count), ...
        m2c_opaque_ptr(reqs0, 'MPI_Request *'), ...
        coder.wref(idx), coder.wref(flag), ...
        coder.opaque('MPI_Status *', 'MPI_STATUS_IGNORE'));
    m2c_rref(reqs0);  %#ok<NASGU>
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
%! reqs.data = [req1.data; req2.data];

%! [idx1, flag, stat, reqs, info] = mpi_Testany(int32(2), reqs);
%! assert(flag==1 && info==0);
%! assert(isequal(MPI_Request_array(reqs,'get',idx1+1), MPI_REQUEST_NULL));
%! assert(idx1 || MPI_Status(stat,'get','source')==0 && MPI_Status(stat,'get', 'tag')==1);

%! [idx2, flag, stat, reqs, info] = mpi_Testany(int32(2), reqs);
%! assert(flag==1 && info==0);
%! assert(isequal(MPI_Request_array(reqs,'get',idx1+1), MPI_REQUEST_NULL));
%! assert(idx2 || MPI_Status(stat, 'get', 'source')==0 && MPI_Status(stat, 'get', 'tag')==1);

%! assert(idx1+idx2==1);
%! assert(isequal(var1, var2));
