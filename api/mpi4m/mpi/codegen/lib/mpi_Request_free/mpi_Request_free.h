#ifndef MPI_REQUEST_FREE_H
#define MPI_REQUEST_FREE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Request_free_types.h"

extern void mpi_Request_free(M2C_OpaqueType *req, int *info, boolean_T *toplevel);
extern void mpi_Request_free_initialize(void);
extern void mpi_Request_free_terminate(void);

#endif
