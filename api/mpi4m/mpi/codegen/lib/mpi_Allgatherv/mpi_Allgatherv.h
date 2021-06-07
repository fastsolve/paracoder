#ifndef MPI_ALLGATHERV_H
#define MPI_ALLGATHERV_H

#include "mpi_Allgatherv_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void
mpi_Allgatherv(const M2C_OpaquePtrType *sptr, int scount,
               const M2C_OpaqueType *stype, const M2C_OpaquePtrType *rptr,
               const emxArray_int32_T *rcounts, const emxArray_int32_T *disps,
               const M2C_OpaqueType *rtype, const M2C_OpaqueType *comm,
               int *info, boolean_T *toplevel);

extern void mpi_Allgatherv_initialize(void);

extern void mpi_Allgatherv_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
