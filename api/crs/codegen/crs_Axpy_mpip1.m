function b = crs_Axpy_mpip1(A, x, b, nthreads, comm, pbmsg, pbsz) %#codegen

b = crs_Axpy(A, x, b, nthreads, MPI_Comm(comm), pbmsg, pbsz);
