function info = set_errhandler(errhandler) %#codegen
%set_errhandler Set the error handler for MPI_COMM_WORLD
%
%  info = set_errhandler(errhandler)
%
%  errhandler  opaque MPI_Errhandler object
%  info (int) return code

info = mpi_Comm_set_errhandler(MPI_COMM_WORLD, errhandler);
