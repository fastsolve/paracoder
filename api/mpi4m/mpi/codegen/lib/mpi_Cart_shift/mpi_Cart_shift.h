#ifndef MPI_CART_SHIFT_H
#define MPI_CART_SHIFT_H

#include "mpi_Cart_shift_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Cart_shift(const M2C_OpaqueType *comm, int direction, int displ,
                           int *source, int *dest, int *info,
                           boolean_T *toplevel);

extern void mpi_Cart_shift_initialize(void);

extern void mpi_Cart_shift_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
