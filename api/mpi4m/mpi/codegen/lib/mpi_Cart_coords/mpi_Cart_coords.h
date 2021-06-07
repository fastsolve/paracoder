#ifndef MPI_CART_COORDS_H
#define MPI_CART_COORDS_H

#include "mpi_Cart_coords_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Cart_coords(const M2C_OpaqueType *comm, int rank, int maxdims,
                            emxArray_int32_T *coords, int *info,
                            boolean_T *toplevel);

extern void mpi_Cart_coords_initialize(void);

extern void mpi_Cart_coords_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
