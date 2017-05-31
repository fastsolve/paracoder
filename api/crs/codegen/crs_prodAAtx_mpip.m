function [b, Atx] = crs_prodAAtx_mpip( A, x, b, Atx, nthreads, comm, pbmsg) %#codegen

[b, Atx] = crs_prodAAtx( A, x, b, Atx, nthreads, MPI_Comm(comm), pbmsg);
