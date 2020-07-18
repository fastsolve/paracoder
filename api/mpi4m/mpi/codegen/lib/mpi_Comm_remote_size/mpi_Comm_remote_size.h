#ifndef MPI_COMM_REMOTE_SIZE_H
#define MPI_COMM_REMOTE_SIZE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_remote_size_types.h"

extern void mpi_Comm_remote_size(const M2C_OpaqueType *comm, int *size, int
  *info, boolean_T *toplevel);
extern void mpi_Comm_remote_size_initialize(void);
extern void mpi_Comm_remote_size_terminate(void);

#endif
