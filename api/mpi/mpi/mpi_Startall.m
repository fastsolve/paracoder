function [info, toplevel] = mpi_Startall(count, reqs)
%mpi_Startall	Starts a collection of persistent requests
%
%  info = mpi_Startall(count, reqs)
%
%  Input arguments
%      count      list length (integer)
%      reqs       array of requests
%
%  Output arguments
%      info (int) return code
%
%  SEE ALSO: mpi_Start, mpi_Test, mpi_Testall, mpi_Testsome, mpi_Test, 
%     mpi_Wait, mpi_Wait_all, mpi_Wait_any, mpi_Waitsome
%
% C interface:
%   int MPI_Startall(int count, MPI_Request array_of_requests[])
% http://mpi.deino.net/mpi_functions/MPI_Startall.html

%#codegen -args {int32(0), MPI_Request_array}

% This function should not be inlined, because of the handling of arrays.
coder.inline('never');

if isstruct(reqs) && coder.ismatlabthread
    if length(reqs.data) < count*mpi_get_sizeof('MPI_Request')
        m2c_error('mpi_Startall:OutOfBound','Message size is larger than variable size.');
    end
end

info = int32(0); %#ok<NASGU>
info = coder.ceval('MPI_Startall', int32(count), ...
    m2c_opaque_ptr_const(MPI_Request_array(reqs), 'MPI_Request *'));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Startall error code %d\n', info)
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
%! [req0, info] = mpi_Recv_init(m2c_opaque_ptr(var2), count, MPI_DOUBLE, ...
%!        int32(0), int32(1), comm);
%! assert(info==0);
%! [req1, info] = mpi_Send_init(m2c_opaque_ptr_const(var1), count, MPI_DOUBLE, ...
%!        int32(0), int32(1), comm);
%! assert(info==0);
%! reqs = MPI_Request_array(2);
%! reqs = MPI_Request_array(reqs, 'set', 1, req0);
%! reqs = MPI_Request_array(reqs, 'set', 2, req1);
%! 
%! info = mpi_Startall(int32(2), reqs);
%! [req0, info] = mpi_Request_free(req0); assert(isequal(req0,MPI_REQUEST_NULL));
%! [req1, info] = mpi_Request_free(req1); assert(isequal(req1,MPI_REQUEST_NULL));
%! assert(info==0);
%! assert(isequal(var1, var2));
