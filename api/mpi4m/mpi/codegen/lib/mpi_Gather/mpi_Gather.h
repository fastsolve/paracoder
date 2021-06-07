#ifndef MPI_GATHER_H
#define MPI_GATHER_H

#include "mpi_Gather_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Gather(const M2C_OpaquePtrType *sptr, int scount,
                       const M2C_OpaqueType *stype,
                       const M2C_OpaquePtrType *rptr, int rcount,
                       const M2C_OpaqueType *rtype, int root,
                       const M2C_OpaqueType *comm, int *info,
                       boolean_T *toplevel);

extern void mpi_Gather_initialize(void);

extern void mpi_Gather_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
