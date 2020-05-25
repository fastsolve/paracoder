#ifndef MPI_GROUP_RANGE_INCL_H
#define MPI_GROUP_RANGE_INCL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_range_incl_types.h"

extern void mpi_Group_range_incl(const struct0_T *group, int n, const
  emxArray_int32_T *ranges, struct0_T *newgroup, int *info, boolean_T *toplevel);
extern void mpi_Group_range_incl_initialize(void);
extern void mpi_Group_range_incl_terminate(void);

#endif
