#ifndef MPI_GROUP_UNION_H
#define MPI_GROUP_UNION_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_union_types.h"

extern void mpi_Group_union(const M2C_OpaqueType *group1, const M2C_OpaqueType
  *group2, M2C_OpaqueType *newgroup, int *info, boolean_T *toplevel);
extern void mpi_Group_union_initialize(void);
extern void mpi_Group_union_terminate(void);

#endif
