#ifndef MPI_GATHERV_H
#define MPI_GATHERV_H

#include "mpi_Gatherv_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void
mpi_Gatherv(const M2C_OpaquePtrType *sptr, int scount,
            const M2C_OpaqueType *stype, const M2C_OpaquePtrType *rptr,
            const emxArray_int32_T *rcounts, const emxArray_int32_T *disps,
            const M2C_OpaqueType *rtype, int root, const M2C_OpaqueType *comm,
            int *info, boolean_T *toplevel);

extern void mpi_Gatherv_initialize(void);

extern void mpi_Gatherv_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
