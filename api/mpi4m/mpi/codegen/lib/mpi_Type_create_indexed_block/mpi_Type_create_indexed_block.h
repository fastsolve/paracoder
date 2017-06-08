#ifndef MPI_TYPE_CREATE_INDEXED_BLOCK_H
#define MPI_TYPE_CREATE_INDEXED_BLOCK_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Type_create_indexed_block_types.h"

extern void mpi_Type_create_indexed_block(int count, int blocklen, const
  emxArray_int32_T *indices, const struct0_T *oldtype, struct0_T *newtype, int
  *info, boolean_T *toplevel);
extern void mpi_Type_create_indexed_block_initialize(void);
extern void mpi_Type_create_indexed_block_terminate(void);

#endif
