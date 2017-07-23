function b = crs_Axpy_mpip(A, x, b, nthreads, comm, pbmsg) %#codegen

b = crs_Axpy(A, x, b, nthreads, MPI_Comm(comm), pbmsg);
