#ifndef MPI_COMM_SIZE_H
#define MPI_COMM_SIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Comm_size_types.h"

extern void mpi_Comm_size(const struct0_T *comm, int *size, int *info, boolean_T
  *toplevel);
extern void mpi_Comm_size_initialize(void);
extern void mpi_Comm_size_terminate(void);

#endif
