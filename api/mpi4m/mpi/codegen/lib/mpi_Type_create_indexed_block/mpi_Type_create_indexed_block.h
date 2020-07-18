#ifndef MPI_TYPE_CREATE_INDEXED_BLOCK_H
#define MPI_TYPE_CREATE_INDEXED_BLOCK_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Type_create_indexed_block_types.h"

extern void mpi_Type_create_indexed_block(int count, int blocklen, const
  emxArray_int32_T *indices, const M2C_OpaqueType *oldtype, M2C_OpaqueType
  *newtype, int *info, boolean_T *toplevel);
extern void mpi_Type_create_indexed_block_initialize(void);
extern void mpi_Type_create_indexed_block_terminate(void);

#endif
