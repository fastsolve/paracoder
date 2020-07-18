#ifndef MPI_CART_SHIFT_H
#define MPI_CART_SHIFT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Cart_shift_types.h"

extern void mpi_Cart_shift(const M2C_OpaqueType *comm, int direction, int displ,
  int *source, int *dest, int *info, boolean_T *toplevel);
extern void mpi_Cart_shift_initialize(void);
extern void mpi_Cart_shift_terminate(void);

#endif
