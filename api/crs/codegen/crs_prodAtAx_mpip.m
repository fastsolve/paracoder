function [b, Ax] = crs_prodAtAx_mpip(A, x, b, Ax, nthreads, comm, pbmsg) %#codegen

[b, Ax] = crs_prodAtAx(A, x, b, Ax, nthreads, MPI_Comm(comm), pbmsg);
