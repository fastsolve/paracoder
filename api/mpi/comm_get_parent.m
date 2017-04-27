function [comm, info] = comm_get_parent %#codegen
%comm_get_parent  Return the parent communicator for this process
%
%  [comm, info] = comm_get_parent
%
%  comm       Opaque MPI_Comm object.
%  info (int) return code

[comm, info] = mpi_Comm_get_parent;
