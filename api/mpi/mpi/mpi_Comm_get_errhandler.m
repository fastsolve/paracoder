function [errhandler, info, toplevel] = mpi_Comm_get_errhandler(comm)
%mpi_Comm_get_errhandler Get the error handler attached to a communicator.
%
%  [errhandler, info] = mpi_Comm_get_errhandler(comm)
%
%  comm       Opaque MPI_Comm object.
%
%  errhandler Opaque error handler for communicator
%  info (int) return code
%
% C interface:
% int MPI_Comm_get_errhandler(MPI_Comm comm, MPI_Errhandler *errhandler)
% http://mpi.deino.net/mpi_functions/MPI_Comm_get_errhandler.html

%#codegen -args {MPI_Comm}

info = int32(0); %#ok<NASGU>


errh = coder.opaque('MPI_Errhandler');
info = coder.ceval('MPI_Comm_get_errhandler', MPI_Comm(comm), coder.wref(errh));

toplevel = nargout>2;
errhandler = MPI_Errhandler(errh, toplevel);

if info && (toplevel || m2c_debug)
    m2c_error('MPI:RuntimeError', 'MPI_Comm_get_errhandler failed with error message %s\n', mpi_Error_string(info))
end
