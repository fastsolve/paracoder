#ifndef MPI_WAITALL_H
#define MPI_WAITALL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Waitall_types.h"

extern void mpi_Waitall(int count, M2C_OpaqueType *reqs, M2C_OpaqueType *stats,
  int *info, boolean_T *toplevel);
extern void mpi_Waitall_initialize(void);
extern void mpi_Waitall_terminate(void);

#endif
