#ifndef MPI_GROUP_INTERSECTION_H
#define MPI_GROUP_INTERSECTION_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Group_intersection_types.h"

extern void mpi_Group_intersection(const struct0_T *group1, const struct0_T
  *group2, struct0_T *newgroup, int *info, boolean_T *toplevel);
extern void mpi_Group_intersection_initialize(void);
extern void mpi_Group_intersection_terminate(void);

#endif
