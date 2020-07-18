#ifndef MPI_TYPE_INDEXED_H
#define MPI_TYPE_INDEXED_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Type_indexed_types.h"

extern void mpi_Type_indexed(int count, const emxArray_int32_T *blocklens, const
  emxArray_int32_T *indices, const M2C_OpaqueType *oldtype, M2C_OpaqueType
  *newtype, int *info, boolean_T *toplevel);
extern void mpi_Type_indexed_initialize(void);
extern void mpi_Type_indexed_terminate(void);

#endif
