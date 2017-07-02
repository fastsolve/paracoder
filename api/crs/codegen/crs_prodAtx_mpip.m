function b = crs_prodAtx_mpip(A, x, b, nthreads, comm, pbmsg) %#codegen

b = crs_prodAtx(A, x, b, nthreads, MPI_Comm(comm), pbmsg);
