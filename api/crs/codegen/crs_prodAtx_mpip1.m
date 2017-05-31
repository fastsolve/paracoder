function b = crs_prodAtx_mpip1( A, x, b, nthreads, comm, pbmsg, pbsz) %#codegen

b = crs_prodAtx( A, x, b, nthreads, MPI_Comm(comm), pbmsg, pbsz);
