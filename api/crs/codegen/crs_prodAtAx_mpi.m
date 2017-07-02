function [b, Ax] = crs_prodAtAx_mpi(A, x, b, Ax, nthreads, comm) %#codegen

[b, Ax] = crs_prodAtAx(A, x, b, Ax, nthreads, MPI_Comm(comm));
