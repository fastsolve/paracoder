#ifndef MPI_CARTDIM_GET_H
#define MPI_CARTDIM_GET_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Cartdim_get_types.h"

extern void mpi_Cartdim_get(const struct0_T *comm, int *ndims, int *info,
  boolean_T *toplevel);
extern void mpi_Cartdim_get_initialize(void);
extern void mpi_Cartdim_get_terminate(void);

#endif
