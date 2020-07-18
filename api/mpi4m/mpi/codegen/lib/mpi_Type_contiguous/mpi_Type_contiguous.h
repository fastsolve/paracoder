#ifndef MPI_TYPE_CONTIGUOUS_H
#define MPI_TYPE_CONTIGUOUS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Type_contiguous_types.h"

extern void mpi_Type_contiguous(int count, const M2C_OpaqueType *oldtype,
  M2C_OpaqueType *newtype, int *info, boolean_T *toplevel);
extern void mpi_Type_contiguous_initialize(void);
extern void mpi_Type_contiguous_terminate(void);

#endif
