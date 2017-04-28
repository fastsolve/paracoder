#ifndef MPI_GATHER_H
#define MPI_GATHER_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Gather_types.h"

extern void mpi_Gather(const struct0_T *sptr, int scount, const struct1_T *stype,
  const struct0_T *rptr, int rcount, const struct1_T *rtype, int root, const
  struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Gather_initialize(void);
extern void mpi_Gather_terminate(void);

#endif
