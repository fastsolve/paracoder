function [errhandler, info] = get_errhandler %#codegen
%get_errhandler Get the error handler attached to MPI_COMM_WORLD
%
%  [errhandler, info] = get_errhandler
%
%  errhandler  opaque MPI_Errhandler object
%  info (int)  return code

[errhandler, info] = mpi_Comm_get_errhandler(MPI_COMM_WORLD);
