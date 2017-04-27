function [flag, stat, info, toplevel] = mpi_Request_get_status(req)
%mpi_Request_get_status  Nondestructive test for the completion of a request
%
%  [flag, stat, info] = MPI_Request_get_status(req)
%
%Input argument:
%  req  - communication request (MPI_Request)
%
%Output argument:
%  flag - true if operation completed (int32)
%  stat - tatus object (MPI_Status)
%  info - return code (int32)
%
%  SEE ALSO: MPI_Test, mpi_Testall, mpi_Testsom, mpi_Testany, mpi_Wait,
%  mpi_Wait_all, mpi_Waitsome, mpi_Waitany, mpi_Start, mpi_Startall
%
% C interface:
%   int MPI_Request_get_status(MPI_Request request, int *flag, MPI_Status *status)
% http://mpi.deino.net/mpi_functions/MPI_Request_get_status.html

%#codegen -args {MPI_Request}

flag = int32(0);
info = int32(0); %#ok<NASGU>

t_req = MPI_Request(req);
if nargout>1
    stat0 = coder.opaque('MPI_Status');
    info = coder.ceval('MPI_Request_get_status', t_req, ...
        coder.wref(flag), coder.wref(stat0));
    
    toplevel = nargout>3;
    stat = MPI_Status(stat0, toplevel);

    if info && (toplevel || m2c_debug)
        m2c_error('MPI:RuntimeError', 'MPI_Request_get_status failed with error message %s\n', mpi_Error_string(info))
    end
else
    info = coder.ceval('MPI_Request_get_status', t_req, ...
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
%! [flag, stat] = mpi_Request_get_status(req);
%! assert(flag==1);
%! assert(isequal(var1, var2));
%! req = mpi_Request_free(req); assert(isequal(req, MPI_REQUEST_NULL));
