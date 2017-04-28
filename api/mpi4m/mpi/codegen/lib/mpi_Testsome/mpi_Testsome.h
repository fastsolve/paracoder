#ifndef MPI_TESTSOME_H
#define MPI_TESTSOME_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Testsome_types.h"

extern void mpi_Testsome(int count, struct0_T *reqs, emxArray_int32_T *idxs,
  struct0_T *stats, int *info, boolean_T *toplevel);
extern void mpi_Testsome_initialize(void);
extern void mpi_Testsome_terminate(void);

#endif
