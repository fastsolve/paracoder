#ifndef MPI_SCATTERV_H
#define MPI_SCATTERV_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Scatterv_types.h"

extern void mpi_Scatterv(const struct0_T *sptr, const emxArray_int32_T *scounts,
  const emxArray_int32_T *disps, const struct1_T *stype, const struct0_T *rptr,
  int rcount, const struct1_T *rtype, int root, const struct1_T *comm, int *info,
  boolean_T *toplevel);
extern void mpi_Scatterv_initialize(void);
extern void mpi_Scatterv_terminate(void);

#endif
