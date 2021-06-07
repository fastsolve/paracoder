#ifndef MPI_CART_GET_H
#define MPI_CART_GET_H

#include "mpi_Cart_get_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Cart_get(const M2C_OpaqueType *comm, int maxdims,
                         emxArray_int32_T *dims, emxArray_int32_T *periods,
                         emxArray_int32_T *coords, int *info,
                         boolean_T *toplevel);

extern void mpi_Cart_get_initialize(void);

extern void mpi_Cart_get_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
