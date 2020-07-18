#ifndef MPI_ALLGATHERV_H
#define MPI_ALLGATHERV_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Allgatherv_types.h"

extern void mpi_Allgatherv(const M2C_OpaquePtrType *sptr, int scount, const
  M2C_OpaqueType *stype, const M2C_OpaquePtrType *rptr, const emxArray_int32_T
  *rcounts, const emxArray_int32_T *disps, const M2C_OpaqueType *rtype, const
  M2C_OpaqueType *comm, int *info, boolean_T *toplevel);
extern void mpi_Allgatherv_initialize(void);
extern void mpi_Allgatherv_terminate(void);

#endif
