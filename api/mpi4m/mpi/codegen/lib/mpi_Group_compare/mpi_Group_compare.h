#ifndef MPI_GROUP_COMPARE_H
#define MPI_GROUP_COMPARE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_compare_types.h"

extern void mpi_Group_compare(const M2C_OpaqueType *group1, const M2C_OpaqueType
  *group2, int *result, int *info, boolean_T *toplevel);
extern void mpi_Group_compare_initialize(void);
extern void mpi_Group_compare_terminate(void);

#endif
