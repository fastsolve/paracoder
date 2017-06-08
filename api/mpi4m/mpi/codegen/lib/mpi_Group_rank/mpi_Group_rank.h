#ifndef MPI_GROUP_RANK_H
#define MPI_GROUP_RANK_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Group_rank_types.h"

extern void mpi_Group_rank(const struct0_T *group, int *rank, int *info,
  boolean_T *toplevel);
extern void mpi_Group_rank_initialize(void);
extern void mpi_Group_rank_terminate(void);

#endif
