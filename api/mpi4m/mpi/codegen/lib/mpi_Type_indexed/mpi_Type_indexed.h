#ifndef MPI_TYPE_INDEXED_H
#define MPI_TYPE_INDEXED_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Type_indexed_types.h"

extern void mpi_Type_indexed(int count, const emxArray_int32_T *blocklens, const
  emxArray_int32_T *indices, const struct0_T *oldtype, struct0_T *newtype, int
  *info, boolean_T *toplevel);
extern void mpi_Type_indexed_initialize(void);
extern void mpi_Type_indexed_terminate(void);

#endif
