#ifndef MPI_DIMS_CREATE_H
#define MPI_DIMS_CREATE_H

#include "mpi_Dims_create_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Dims_create(int nnodes, int ndims, emxArray_int32_T *dims,
                            int *info, boolean_T *toplevel);

extern void mpi_Dims_create_initialize(void);

extern void mpi_Dims_create_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
