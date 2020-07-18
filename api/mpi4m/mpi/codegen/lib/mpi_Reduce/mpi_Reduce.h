#ifndef MPI_REDUCE_H
#define MPI_REDUCE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Reduce_types.h"

extern void mpi_Reduce(const M2C_OpaquePtrType *sptr, const M2C_OpaquePtrType
  *rptr, int count, const M2C_OpaqueType *datatype, const M2C_OpaqueType *op,
  int root, const M2C_OpaqueType *comm, int *info, boolean_T *toplevel);
extern void mpi_Reduce_initialize(void);
extern void mpi_Reduce_terminate(void);

#endif
