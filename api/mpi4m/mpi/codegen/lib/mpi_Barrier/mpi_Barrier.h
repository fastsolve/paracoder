#ifndef MPI_BARRIER_H
#define MPI_BARRIER_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Barrier_types.h"

extern void mpi_Barrier(const struct0_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Barrier_initialize(void);
extern void mpi_Barrier_terminate(void);

#endif
