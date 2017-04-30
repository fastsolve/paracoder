function b = crs_prodAtx_mpi( A, x, b, nthreads, comm) %#codegen

b = crs_prodAtx( A, x, b, nthreads, MPI_Comm(comm));

end
