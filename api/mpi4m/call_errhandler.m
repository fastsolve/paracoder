function info = call_errhandler(errorcode) %#codegen
%call_errhandler Call the error handler installed on MPI_COMM_WORLD
%
%  info = call_errhandler(errorcode)
%
%  errorcode  error code (integer)
%
%  info (int) return code

info = mpi_Comm_call_errhandler(MPI_COMM_WORLD, int32(errorcode));
