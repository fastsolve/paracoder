#ifndef MPI_WAITALL_H
#define MPI_WAITALL_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Waitall_types.h"

extern void mpi_Waitall(int count, struct0_T *reqs, struct0_T *stats, int *info,
  boolean_T *toplevel);
extern void mpi_Waitall_initialize(void);
extern void mpi_Waitall_terminate(void);

#endif
