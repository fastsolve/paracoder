#ifndef MPI_SCATTERV_H
#define MPI_SCATTERV_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Scatterv_types.h"

extern void mpi_Scatterv(const M2C_OpaquePtrType *sptr, const emxArray_int32_T
  *scounts, const emxArray_int32_T *disps, const M2C_OpaqueType *stype, const
  M2C_OpaquePtrType *rptr, int rcount, const M2C_OpaqueType *rtype, int root,
  const M2C_OpaqueType *comm, int *info, boolean_T *toplevel);
extern void mpi_Scatterv_initialize(void);
extern void mpi_Scatterv_terminate(void);

#endif
