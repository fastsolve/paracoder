#ifndef MPI_WAITANY_H
#define MPI_WAITANY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Waitany_types.h"

extern void mpi_Waitany(int count, M2C_OpaqueType *reqs, int *idx,
  M2C_OpaqueType *stat, int *info, boolean_T *toplevel);
extern void mpi_Waitany_initialize(void);
extern void mpi_Waitany_terminate(void);

#endif
