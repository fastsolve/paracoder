#ifndef MPI_START_H
#define MPI_START_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Start_types.h"

extern void mpi_Start(const struct0_T *req, int *info, boolean_T *toplevel);
extern void mpi_Start_initialize(void);
extern void mpi_Start_terminate(void);

#endif
