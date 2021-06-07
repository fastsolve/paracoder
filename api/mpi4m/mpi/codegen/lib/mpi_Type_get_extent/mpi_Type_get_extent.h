#ifndef MPI_TYPE_GET_EXTENT_H
#define MPI_TYPE_GET_EXTENT_H

#include "mpi_Type_get_extent_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Type_get_extent(const M2C_OpaqueType *datatype,
                                M2C_OpaqueType *lb, M2C_OpaqueType *extent,
                                int *info, boolean_T *toplevel);

extern void mpi_Type_get_extent_initialize(void);

extern void mpi_Type_get_extent_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
