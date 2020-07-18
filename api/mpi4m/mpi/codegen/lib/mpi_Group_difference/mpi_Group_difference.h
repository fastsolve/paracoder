#ifndef MPI_GROUP_DIFFERENCE_H
#define MPI_GROUP_DIFFERENCE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_difference_types.h"

extern void mpi_Group_difference(const M2C_OpaqueType *group1, const
  M2C_OpaqueType *group2, M2C_OpaqueType *newgroup, int *info, boolean_T
  *toplevel);
extern void mpi_Group_difference_initialize(void);
extern void mpi_Group_difference_terminate(void);

#endif
