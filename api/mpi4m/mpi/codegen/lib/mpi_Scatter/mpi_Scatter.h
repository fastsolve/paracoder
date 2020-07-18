#ifndef MPI_SCATTER_H
#define MPI_SCATTER_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Scatter_types.h"

extern void mpi_Scatter(const M2C_OpaquePtrType *sptr, int scount, const
  M2C_OpaqueType *stype, const M2C_OpaquePtrType *rptr, int rcount, const
  M2C_OpaqueType *rtype, int root, const M2C_OpaqueType *comm, int *info,
  boolean_T *toplevel);
extern void mpi_Scatter_initialize(void);
extern void mpi_Scatter_terminate(void);

#endif
