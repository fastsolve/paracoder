#ifndef MPI_ALLTOALLW_H
#define MPI_ALLTOALLW_H

#include "mpi_Alltoallw_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void
mpi_Alltoallw(const M2C_OpaquePtrType *sptr, const emxArray_int32_T *scounts,
              const emxArray_int32_T *sdisps, const M2C_OpaqueType *stypes,
              const M2C_OpaquePtrType *rptr, const emxArray_int32_T *rcounts,
              const emxArray_int32_T *rdisps, const M2C_OpaqueType *rtypes,
              const M2C_OpaqueType *comm, int *info, boolean_T *toplevel);

extern void mpi_Alltoallw_initialize(void);

extern void mpi_Alltoallw_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
