#ifndef MPI_GROUP_RANGE_INCL_H
#define MPI_GROUP_RANGE_INCL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_range_incl_types.h"

extern void mpi_Group_range_incl(const M2C_OpaqueType *group, int n, const
  emxArray_int32_T *ranges, M2C_OpaqueType *newgroup, int *info, boolean_T
  *toplevel);
extern void mpi_Group_range_incl_initialize(void);
extern void mpi_Group_range_incl_terminate(void);

#endif
