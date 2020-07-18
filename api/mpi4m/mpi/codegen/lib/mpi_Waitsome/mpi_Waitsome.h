#ifndef MPI_WAITSOME_H
#define MPI_WAITSOME_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Waitsome_types.h"

extern void mpi_Waitsome(int count, M2C_OpaqueType *reqs, emxArray_int32_T *idxs,
  M2C_OpaqueType *stats, int *info, boolean_T *toplevel);
extern void mpi_Waitsome_initialize(void);
extern void mpi_Waitsome_terminate(void);

#endif
