function [info, toplevel] = mpi_Comm_set_errhandler(comm, errhandler)
%mpi_Comm_set_errhandler Set the error handler for a communicator
%
%  info = mpi_Comm_set_errhandler(comm, errhandler)
%
%  comm       Opaque MPI_Comm object.
%  errhandler Opaque error handler for communicator
%
%  info (int) return code
%
% C interface:
% int MPI_Comm_set_errhandler(MPI_Comm comm, MPI_Errhandler errhandler)
% http://mpi.deino.net/mpi_functions/MPI_Comm_set_errhandler.html

%#codegen -args {MPI_Comm, MPI_Errhandler}

info = int32(0); %#ok<NASGU>

info = coder.ceval('MPI_Comm_set_errhandler', ...
    MPI_Comm(comm), MPI_Errhandler(errhandler));

toplevel = nargout>1;
if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_set_errhandler failed with error message %s\n', mpi_Error_string(info))
end
