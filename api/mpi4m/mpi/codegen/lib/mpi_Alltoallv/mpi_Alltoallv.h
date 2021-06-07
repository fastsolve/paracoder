#ifndef MPI_ALLTOALLV_H
#define MPI_ALLTOALLV_H

#include "mpi_Alltoallv_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void
mpi_Alltoallv(const M2C_OpaquePtrType *sptr, const emxArray_int32_T *scounts,
              const emxArray_int32_T *sdisps, const M2C_OpaqueType *stype,
              const M2C_OpaquePtrType *rptr, const emxArray_int32_T *rcounts,
              const emxArray_int32_T *rdisps, const M2C_OpaqueType *rtype,
              const M2C_OpaqueType *comm, int *info, boolean_T *toplevel);

extern void mpi_Alltoallv_initialize(void);

extern void mpi_Alltoallv_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
