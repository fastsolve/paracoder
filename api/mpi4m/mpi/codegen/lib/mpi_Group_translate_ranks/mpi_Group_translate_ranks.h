#ifndef MPI_GROUP_TRANSLATE_RANKS_H
#define MPI_GROUP_TRANSLATE_RANKS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Group_translate_ranks_types.h"

extern void mpi_Group_translate_ranks(const struct0_T *group1, int n, const
  emxArray_int32_T *ranks1, const struct0_T *group2, emxArray_int32_T *ranks2,
  int *info, boolean_T *toplevel);
extern void mpi_Group_translate_ranks_initialize(void);
extern void mpi_Group_translate_ranks_terminate(void);

#endif
