function b = crs_prodAx_mpip( A, x, b, nthreads, comm, pbmsg) %#codegen

b = crs_prodAx( A, x, b, nthreads, MPI_Comm(comm), pbmsg);
