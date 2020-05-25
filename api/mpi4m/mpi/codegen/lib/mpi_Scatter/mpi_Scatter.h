#ifndef MPI_SCATTER_H
#define MPI_SCATTER_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Scatter_types.h"

extern void mpi_Scatter(const struct0_T *sptr, int scount, const struct1_T
  *stype, const struct0_T *rptr, int rcount, const struct1_T *rtype, int root,
  const struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Scatter_initialize(void);
extern void mpi_Scatter_terminate(void);

#endif
