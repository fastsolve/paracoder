#ifndef MPI_ALLGATHER_H
#define MPI_ALLGATHER_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Allgather_types.h"

extern void mpi_Allgather(const struct0_T *sptr, int scount, const struct1_T
  *stype, const struct0_T *rptr, int rcount, const struct1_T *rtype, const
  struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Allgather_initialize(void);
extern void mpi_Allgather_terminate(void);

#endif
