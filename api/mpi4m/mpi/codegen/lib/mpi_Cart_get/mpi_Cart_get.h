#ifndef MPI_CART_GET_H
#define MPI_CART_GET_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Cart_get_types.h"

extern void mpi_Cart_get(const struct0_T *comm, int maxdims, emxArray_int32_T
  *dims, emxArray_int32_T *periods, emxArray_int32_T *coords, int *info,
  boolean_T *toplevel);
extern void mpi_Cart_get_initialize(void);
extern void mpi_Cart_get_terminate(void);

#endif
