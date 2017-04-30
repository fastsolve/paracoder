function [b, Atx] = crs_prodAAtx_mpi( A, x, b, Atx, nthreads, comm) %#codegen

[b, Atx] = crs_prodAAtx( A, x, b, Atx, nthreads, MPI_Comm(comm));
