#ifndef MPI_TYPE_VECTOR_H
#define MPI_TYPE_VECTOR_H

#include "mpi_Type_vector_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Type_vector(int count, int blocklen, int stride,
                            const M2C_OpaqueType *oldtype,
                            M2C_OpaqueType *newtype, int *info,
                            boolean_T *toplevel);

extern void mpi_Type_vector_initialize(void);

extern void mpi_Type_vector_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
