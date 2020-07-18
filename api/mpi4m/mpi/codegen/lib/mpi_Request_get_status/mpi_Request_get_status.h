#ifndef MPI_REQUEST_GET_STATUS_H
#define MPI_REQUEST_GET_STATUS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Request_get_status_types.h"

extern void mpi_Request_get_status(const M2C_OpaqueType *req, int *flag,
  M2C_OpaqueType *stat, int *info, boolean_T *toplevel);
extern void mpi_Request_get_status_initialize(void);
extern void mpi_Request_get_status_terminate(void);

#endif
