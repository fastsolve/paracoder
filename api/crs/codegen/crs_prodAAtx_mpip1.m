function [b, Atx] = crs_prodAAtx_mpip1(A, x, b, Atx, nthreads, comm, pbmsg, pbsz) %#codegen

[b, Atx] = crs_prodAAtx(A, x, b, Atx, nthreads, MPI_Comm(comm), pbmsg, pbsz);
