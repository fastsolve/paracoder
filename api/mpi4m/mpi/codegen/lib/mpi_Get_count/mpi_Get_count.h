#ifndef MPI_GET_COUNT_H
#define MPI_GET_COUNT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Get_count_types.h"

extern void mpi_Get_count(const struct0_T *stat, const struct0_T *datatype, int *
  count, int *info, boolean_T *toplevel);
extern void mpi_Get_count_initialize(void);
extern void mpi_Get_count_terminate(void);

#endif
