#ifndef MPI_ALLTOALL_H
#define MPI_ALLTOALL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Alltoall_types.h"

extern void mpi_Alltoall(const struct0_T *sptr, int scount, const struct1_T
  *stype, const struct0_T *rptr, int rcount, const struct1_T *rtype, const
  struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Alltoall_initialize(void);
extern void mpi_Alltoall_terminate(void);

#endif
