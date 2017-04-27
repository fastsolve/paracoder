#ifndef MPI_DIMS_CREATE_H
#define MPI_DIMS_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Dims_create_types.h"

extern emxArray_int32_T *emxCreateND_int32_T(int numDimensions, int *size);
extern emxArray_int32_T *emxCreateWrapperND_int32_T(int *data, int numDimensions,
  int *size);
extern emxArray_int32_T *emxCreateWrapper_int32_T(int *data, int rows, int cols);
extern emxArray_int32_T *emxCreate_int32_T(int rows, int cols);
extern void emxDestroyArray_int32_T(emxArray_int32_T *emxArray);
extern void emxInitArray_int32_T(emxArray_int32_T **pEmxArray, int numDimensions);
extern void mpi_Dims_create(int nnodes, int ndims, emxArray_int32_T *dims, int
  *info, boolean_T *toplevel);
extern void mpi_Dims_create_initialize(void);
extern void mpi_Dims_create_terminate(void);

#endif
