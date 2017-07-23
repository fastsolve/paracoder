function b = crs_Axpy_mpi(A, x, b, nthreads, comm) %#codegen

b = crs_Axpy(A, x, b, nthreads, MPI_Comm(comm));
