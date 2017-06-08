#ifndef MPI_CART_CREATE_H
#define MPI_CART_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Cart_create_types.h"

extern void mpi_Cart_create(const struct0_T *comm, int ndims, const
  emxArray_int32_T *dims, const emxArray_int32_T *periods, int reorder,
  struct0_T *newcomm, int *info, boolean_T *toplevel);
extern void mpi_Cart_create_initialize(void);
extern void mpi_Cart_create_terminate(void);

#endif
