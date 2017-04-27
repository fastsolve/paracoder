function [info, toplevel] = mpi_Start(req)
%mpi_Start  Initiates a communication with a persistent request handle
%
%  info = MPI_Start(req)
%
%  req:    communication request
%  info:   return code
%
%  SEE ALSO: mpi_Startall, mpi_Testall, mpi_Testany, mpi_Testsom, 
%      mpi_Waitall, mpi_Waitany, mpi_Waitsome, mpi_Request_free,
%      mpi_Bsend_init, mpi_Ssend_init, mpi_Isend_init, mpi_Recv_init
%
%  This function starts a communication that was previously initialized
%  with any of the mpi_*_init functions.
%
% C interface:
%   int MPI_Start(MPI_Request *request)
% http://mpi.deino.net/mpi_functions/MPI_Start.html

%#codegen -args {MPI_Request}

info = int32(0); %#ok<NASGU>

t_req = MPI_Request(req);
info = coder.ceval('MPI_Start', coder.ref(t_req));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Start error code %d\n', info)
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
%! [req0,info] = mpi_Irecv(m2c_opaque_ptr(var2), count, MPI_DOUBLE, ...
%!        int32(0), int32(1), comm);
%! assert(info==0);
%! [req1, info] = mpi_Send_init(m2c_opaque_ptr_const(var1), count, ...
%!        MPI_DOUBLE, int32(0), int32(1), comm);
%! assert(info==0);
%! info = mpi_Start(req1);
%! assert(info==0);
%! mpi_Wait(req0); 
%M mpi_Request_free(req1);
%! assert(isequal(var1, var2));
