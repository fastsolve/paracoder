function [flag, stat, req, info, toplevel] = mpi_Test(req)
%mpi_Test	Tests for the completion of a request
%
%  [flag, stat, req, info] = MPI_Test(req)
%
%  req (INOUT) communication request. If the communication object
%      associated with this request was created by a nonblocking send
%      or receive call, then the object is deallocated by the call to
%      mpi_Test and the request handle is set to MPI_REQUEST_NULL.
%
%  flag (int) true if operation completed
%  stat is an MPI_Status object
%  info (int) return code
%
%  SEE ALSO: mpi_Testall, mpi_Testsome, mpi_Testany, mpi_Wait,
%  mpi_Wait_all, mpi_Waitsome, mpi_Waitany, mpi_Start, mpi_Startall
%
% C interface:
%   int MPI_Test(MPI_Request *request, int *flag, MPI_Status *status)
% http://mpi.deino.net/mpi_functions/MPI_Test.html
% http://www.mpi-forum.org/docs/mpi21-report/node58.htm

%#codegen -args {MPI_Request}

flag = int32(0);
info = int32(0); %#ok<NASGU>

t_req = MPI_Request(req);
if nargout>1
    stat0 = coder.opaque('MPI_Status');
    info = coder.ceval('MPI_Test', coder.ref(t_req), ...
        coder.wref(flag), coder.wref(stat0));
    
    toplevel = nargout>4;
    req = MPI_Request(t_req, toplevel);
    stat = MPI_Status(stat0, toplevel);
    
    if info && (toplevel || m2c_debug)
        m2c_error('MPI:RuntimeError', 'MPI_Test failed with error message %s\n', mpi_Error_string(info))
    end
else
    info = coder.ceval('MPI_Test', coder.ref(t_req), ...
        coder.wref(flag), coder.opaque('MPI_Status *', 'MPI_STATUS_IGNORE'));
end

function test %#ok<DEFNU>
%!test
%! if ~mpi_Initialized; mpi_Init; end
%!
%! comm = MPI_COMM_WORLD;
%! var1 = rand(10,10);
%! count = int32(numel(var1));
%! var2 = zeros(10,10);
%!
%! [req,info] = mpi_Isend(m2c_opaque_ptr_const(var1), count, MPI_DOUBLE, ...
%!      int32(0), int32(1), comm);  assert(info==0);
%! [stat, info] = mpi_Recv(m2c_opaque_ptr(var2), count, MPI_DOUBLE, ...
%!     int32(0), int32(1), comm);  assert(info==0);
%! assert(MPI_Status(stat, 'get', 'source')==0 && MPI_Status(stat, 'get', 'tag')==1);
%!
%! % Wait for the completion of
%! [flag, stat, req] = mpi_Test(req);
%! assert(isequal(req, MPI_REQUEST_NULL));
%! assert(flag==1);
%! assert(isequal(var1, var2));
