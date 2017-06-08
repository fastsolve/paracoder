#ifndef MPI_REDUCE_SCATTER_H
#define MPI_REDUCE_SCATTER_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Reduce_scatter_types.h"

extern void mpi_Reduce_scatter(const struct0_T *sptr, const struct0_T *rptr,
  const emxArray_int32_T *rcounts, const struct1_T *datatype, const struct1_T
  *op, const struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Reduce_scatter_initialize(void);
extern void mpi_Reduce_scatter_terminate(void);

#endif
