#ifndef MPI_CART_GET_H
#define MPI_CART_GET_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Cart_get_types.h"

extern void mpi_Cart_get(const M2C_OpaqueType *comm, int maxdims,
  emxArray_int32_T *dims, emxArray_int32_T *periods, emxArray_int32_T *coords,
  int *info, boolean_T *toplevel);
extern void mpi_Cart_get_initialize(void);
extern void mpi_Cart_get_terminate(void);

#endif
