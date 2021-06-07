#ifndef MPI_TYPE_INDEXED_H
#define MPI_TYPE_INDEXED_H

#include "mpi_Type_indexed_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Type_indexed(int count, const emxArray_int32_T *blocklens,
                             const emxArray_int32_T *indices,
                             const M2C_OpaqueType *oldtype,
                             M2C_OpaqueType *newtype, int *info,
                             boolean_T *toplevel);

extern void mpi_Type_indexed_initialize(void);

extern void mpi_Type_indexed_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
