#ifndef MPI_ALLREDUCE_H
#define MPI_ALLREDUCE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Allreduce_types.h"

extern void mpi_Allreduce(const struct0_T *sptr, const struct0_T *rptr, int
  count, const struct1_T *datatype, const struct1_T *op, const struct1_T *comm,
  int *info, boolean_T *toplevel);
extern void mpi_Allreduce_initialize(void);
extern void mpi_Allreduce_terminate(void);

#endif
