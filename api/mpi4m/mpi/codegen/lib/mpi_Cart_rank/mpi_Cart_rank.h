#ifndef MPI_CART_RANK_H
#define MPI_CART_RANK_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Cart_rank_types.h"

extern void mpi_Cart_rank(const M2C_OpaqueType *comm, const emxArray_int32_T
  *coords, int *rank, int *info, boolean_T *toplevel);
extern void mpi_Cart_rank_initialize(void);
extern void mpi_Cart_rank_terminate(void);

#endif
