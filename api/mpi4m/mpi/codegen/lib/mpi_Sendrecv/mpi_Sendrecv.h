#ifndef MPI_SENDRECV_H
#define MPI_SENDRECV_H

#include "mpi_Sendrecv_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Sendrecv(const M2C_OpaquePtrType *sptr, int scount,
                         const M2C_OpaqueType *stype, int dst, int stag,
                         const M2C_OpaquePtrType *rptr, int rcount,
                         const M2C_OpaqueType *rtype, int src, int rtag,
                         const M2C_OpaqueType *comm, M2C_OpaqueType *stat,
                         int *info, boolean_T *toplevel);

extern void mpi_Sendrecv_initialize(void);

extern void mpi_Sendrecv_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
