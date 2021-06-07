#ifndef MPI_CART_MAP_H
#define MPI_CART_MAP_H

#include "mpi_Cart_map_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Cart_map(const M2C_OpaqueType *comm, int ndims,
                         const emxArray_int32_T *dims,
                         const emxArray_int32_T *periods, int *newrank,
                         int *info, boolean_T *toplevel);

extern void mpi_Cart_map_initialize(void);

extern void mpi_Cart_map_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
