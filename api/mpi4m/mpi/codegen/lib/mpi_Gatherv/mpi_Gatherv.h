#ifndef MPI_GATHERV_H
#define MPI_GATHERV_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Gatherv_types.h"

extern void mpi_Gatherv(const struct0_T *sptr, int scount, const struct1_T
  *stype, const struct0_T *rptr, const emxArray_int32_T *rcounts, const
  emxArray_int32_T *disps, const struct1_T *rtype, int root, const struct1_T
  *comm, int *info, boolean_T *toplevel);
extern void mpi_Gatherv_initialize(void);
extern void mpi_Gatherv_terminate(void);

#endif
