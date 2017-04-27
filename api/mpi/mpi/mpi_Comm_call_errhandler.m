function [info, toplevel] = mpi_Comm_call_errhandler(comm, errorcode)
%mpi_Comm_call_errhandler Call the error handler installed on a communicator
%
%  info = mpi_Comm_call_errhandler(comm, errorcode)
%
%  comm       Opaque MPI_Comm object.
%  errorcode  error code (integer)
%
%  info (int) return code
%
% C interface:
% int int MPI_Comm_call_errhandler(MPI_Comm comm, int errorcode);
% http://mpi.deino.net/mpi_functions/MPI_Comm_call_errhandler.html

%#codegen -args {MPI_Comm, int32(0)}

info = int32(0); %#ok<NASGU>

info = coder.ceval('MPI_Comm_call_errhandler', ...
    MPI_Comm(comm), int32(errorcode));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_call_errhandler failed with error message %s\n', mpi_Error_string(info))
end
