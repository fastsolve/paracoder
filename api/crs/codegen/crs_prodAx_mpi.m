function b = crs_prodAx_mpi( A, x, b, nthreads, comm) %#codegen

b = crs_prodAx( A, x, b, nthreads, MPI_Comm(comm));
