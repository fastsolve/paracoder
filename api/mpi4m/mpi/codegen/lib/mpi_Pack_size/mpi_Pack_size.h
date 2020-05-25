#ifndef MPI_PACK_SIZE_H
#define MPI_PACK_SIZE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Pack_size_types.h"

extern void mpi_Pack_size(int count, const struct0_T *datatype, const struct0_T *
  comm, int *size, int *info, boolean_T *toplevel);
extern void mpi_Pack_size_initialize(void);
extern void mpi_Pack_size_terminate(void);

#endif
