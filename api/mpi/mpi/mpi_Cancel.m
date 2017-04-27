function [info, toplevel] = mpi_Cancel(req)
%mpi_Cancel   Cancels a communication request
%
%  info = mpi_Cancel (req)
%
%  req communication request (handle returned by MPI_Irecv)
%
%  info (int) return code
%
%  SEE ALSO: mpi_Test[all,some,any], mpi_Wait[all,some,any], mpi_Test_cancelled
%
% C interface:
%   int MPI_Cancel(MPI_Request *request)
% http://mpi.deino.net/mpi_functions/MPI_Cancel.html

%#codegen -args {MPI_Request}

info = int32(0); %#ok<NASGU>

t_req = MPI_Request(req);
info = coder.ceval('MPI_Cancel', coder.ref(t_req));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Cancel failed with error message %s\n', mpi_Error_string(info))
end
