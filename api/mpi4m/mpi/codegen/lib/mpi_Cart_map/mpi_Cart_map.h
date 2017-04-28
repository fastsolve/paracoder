#ifndef MPI_CART_MAP_H
#define MPI_CART_MAP_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Cart_map_types.h"

extern void mpi_Cart_map(const struct0_T *comm, int ndims, const
  emxArray_int32_T *dims, const emxArray_int32_T *periods, int *newrank, int
  *info, boolean_T *toplevel);
extern void mpi_Cart_map_initialize(void);
extern void mpi_Cart_map_terminate(void);

#endif
