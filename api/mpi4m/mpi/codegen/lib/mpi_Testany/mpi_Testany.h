#ifndef MPI_TESTANY_H
#define MPI_TESTANY_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Testany_types.h"

extern void mpi_Testany(int count, M2C_OpaqueType *reqs, int *idx, int *flag,
  M2C_OpaqueType *stat, int *info, boolean_T *toplevel);
extern void mpi_Testany_initialize(void);
extern void mpi_Testany_terminate(void);

#endif
