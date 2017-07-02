function b = crs_prodAx_mpip1(A, x, b, nthreads, comm, pbmsg, pbsz) %#codegen

b = crs_prodAx(A, x, b, nthreads, MPI_Comm(comm), pbmsg, pbsz);
