#ifndef MPI_CART_COORDS_H
#define MPI_CART_COORDS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Cart_coords_types.h"

extern void mpi_Cart_coords(const struct0_T *comm, int rank, int maxdims,
  emxArray_int32_T *coords, int *info, boolean_T *toplevel);
extern void mpi_Cart_coords_initialize(void);
extern void mpi_Cart_coords_terminate(void);

#endif
