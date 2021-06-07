#ifndef MPI_SCATTERV_H
#define MPI_SCATTERV_H

#include "mpi_Scatterv_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void
mpi_Scatterv(const M2C_OpaquePtrType *sptr, const emxArray_int32_T *scounts,
             const emxArray_int32_T *disps, const M2C_OpaqueType *stype,
             const M2C_OpaquePtrType *rptr, int rcount,
             const M2C_OpaqueType *rtype, int root, const M2C_OpaqueType *comm,
             int *info, boolean_T *toplevel);

extern void mpi_Scatterv_initialize(void);

extern void mpi_Scatterv_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
