#ifndef MPI_TYPE_SIZE_H
#define MPI_TYPE_SIZE_H

#include "mpi_Type_size_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Type_size(const M2C_OpaqueType *datatype, int *size, int *info,
                          boolean_T *toplevel);

extern void mpi_Type_size_initialize(void);

extern void mpi_Type_size_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
