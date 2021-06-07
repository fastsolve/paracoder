#ifndef MPI_CART_CREATE_H
#define MPI_CART_CREATE_H

#include "mpi_Cart_create_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Cart_create(const M2C_OpaqueType *comm, int ndims,
                            const emxArray_int32_T *dims,
                            const emxArray_int32_T *periods, int reorder,
                            M2C_OpaqueType *newcomm, int *info,
                            boolean_T *toplevel);

extern void mpi_Cart_create_initialize(void);

extern void mpi_Cart_create_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
