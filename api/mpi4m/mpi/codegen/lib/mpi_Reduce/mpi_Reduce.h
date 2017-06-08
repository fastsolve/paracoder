#ifndef MPI_REDUCE_H
#define MPI_REDUCE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Reduce_types.h"

extern void mpi_Reduce(const struct0_T *sptr, const struct0_T *rptr, int count,
  const struct1_T *datatype, const struct1_T *op, int root, const struct1_T
  *comm, int *info, boolean_T *toplevel);
extern void mpi_Reduce_initialize(void);
extern void mpi_Reduce_terminate(void);

#endif
