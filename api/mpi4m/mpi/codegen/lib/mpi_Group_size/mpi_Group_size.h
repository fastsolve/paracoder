#ifndef MPI_GROUP_SIZE_H
#define MPI_GROUP_SIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Group_size_types.h"

extern void mpi_Group_size(const struct0_T *group, int *size, int *info,
  boolean_T *toplevel);
extern void mpi_Group_size_initialize(void);
extern void mpi_Group_size_terminate(void);

#endif
