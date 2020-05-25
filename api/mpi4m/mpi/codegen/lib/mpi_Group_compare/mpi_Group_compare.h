#ifndef MPI_GROUP_COMPARE_H
#define MPI_GROUP_COMPARE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_compare_types.h"

extern void mpi_Group_compare(const struct0_T *group1, const struct0_T *group2,
  int *result, int *info, boolean_T *toplevel);
extern void mpi_Group_compare_initialize(void);
extern void mpi_Group_compare_terminate(void);

#endif
