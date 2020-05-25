#ifndef MPI_GROUP_INCL_H
#define MPI_GROUP_INCL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_incl_types.h"

extern void mpi_Group_incl(const struct0_T *group, int n, const emxArray_int32_T
  *ranks, struct0_T *newgroup, int *info, boolean_T *toplevel);
extern void mpi_Group_incl_initialize(void);
extern void mpi_Group_incl_terminate(void);

#endif
