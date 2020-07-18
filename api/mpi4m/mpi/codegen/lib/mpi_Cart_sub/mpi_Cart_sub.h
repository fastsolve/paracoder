#ifndef MPI_CART_SUB_H
#define MPI_CART_SUB_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Cart_sub_types.h"

extern void mpi_Cart_sub(const M2C_OpaqueType *comm, const emxArray_int32_T
  *remain_dims, M2C_OpaqueType *newcomm, int *info, boolean_T *toplevel);
extern void mpi_Cart_sub_initialize(void);
extern void mpi_Cart_sub_terminate(void);

#endif
