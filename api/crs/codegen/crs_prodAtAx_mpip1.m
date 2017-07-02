function [b, Ax] = crs_prodAtAx_mpip1(A, x, b, Ax, nthreads, comm, pbmsg, pbsz) %#codegen

[b, Ax] = crs_prodAtAx(A, x, b, Ax, nthreads, MPI_Comm(comm), pbmsg, pbsz);
