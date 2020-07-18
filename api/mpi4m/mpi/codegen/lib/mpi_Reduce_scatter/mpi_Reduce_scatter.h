#ifndef MPI_REDUCE_SCATTER_H
#define MPI_REDUCE_SCATTER_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Reduce_scatter_types.h"

extern void mpi_Reduce_scatter(const M2C_OpaquePtrType *sptr, const
  M2C_OpaquePtrType *rptr, const emxArray_int32_T *rcounts, const M2C_OpaqueType
  *datatype, const M2C_OpaqueType *op, const M2C_OpaqueType *comm, int *info,
  boolean_T *toplevel);
extern void mpi_Reduce_scatter_initialize(void);
extern void mpi_Reduce_scatter_terminate(void);

#endif
