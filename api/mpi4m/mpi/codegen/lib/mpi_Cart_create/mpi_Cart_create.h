#ifndef MPI_CART_CREATE_H
#define MPI_CART_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Cart_create_types.h"

extern void mpi_Cart_create(const M2C_OpaqueType *comm, int ndims, const
  emxArray_int32_T *dims, const emxArray_int32_T *periods, int reorder,
  M2C_OpaqueType *newcomm, int *info, boolean_T *toplevel);
extern void mpi_Cart_create_initialize(void);
extern void mpi_Cart_create_terminate(void);

#endif
