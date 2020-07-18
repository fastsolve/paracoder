#ifndef MPI_ALLREDUCE_H
#define MPI_ALLREDUCE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Allreduce_types.h"

extern void mpi_Allreduce(const M2C_OpaquePtrType *sptr, const M2C_OpaquePtrType
  *rptr, int count, const M2C_OpaqueType *datatype, const M2C_OpaqueType *op,
  const M2C_OpaqueType *comm, int *info, boolean_T *toplevel);
extern void mpi_Allreduce_initialize(void);
extern void mpi_Allreduce_terminate(void);

#endif
