#ifndef MPI_GROUP_UNION_H
#define MPI_GROUP_UNION_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_union_types.h"

extern void mpi_Group_union(const struct0_T *group1, const struct0_T *group2,
  struct0_T *newgroup, int *info, boolean_T *toplevel);
extern void mpi_Group_union_initialize(void);
extern void mpi_Group_union_terminate(void);

#endif
