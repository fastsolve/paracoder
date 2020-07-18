#ifndef MPI_GROUP_EXCL_H
#define MPI_GROUP_EXCL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_excl_types.h"

extern void mpi_Group_excl(const M2C_OpaqueType *group, int n, const
  emxArray_int32_T *ranks, M2C_OpaqueType *newgroup, int *info, boolean_T
  *toplevel);
extern void mpi_Group_excl_initialize(void);
extern void mpi_Group_excl_terminate(void);

#endif
