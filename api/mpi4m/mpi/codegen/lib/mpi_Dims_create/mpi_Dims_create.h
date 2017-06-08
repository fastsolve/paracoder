#ifndef MPI_DIMS_CREATE_H
#define MPI_DIMS_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Dims_create_types.h"

extern void mpi_Dims_create(int nnodes, int ndims, emxArray_int32_T *dims, int
  *info, boolean_T *toplevel);
extern void mpi_Dims_create_initialize(void);
extern void mpi_Dims_create_terminate(void);

#endif
