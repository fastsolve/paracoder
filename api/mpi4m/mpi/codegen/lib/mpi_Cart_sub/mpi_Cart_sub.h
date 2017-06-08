#ifndef MPI_CART_SUB_H
#define MPI_CART_SUB_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Cart_sub_types.h"

extern void mpi_Cart_sub(const struct0_T *comm, const emxArray_int32_T
  *remain_dims, struct0_T *newcomm, int *info, boolean_T *toplevel);
extern void mpi_Cart_sub_initialize(void);
extern void mpi_Cart_sub_terminate(void);

#endif
