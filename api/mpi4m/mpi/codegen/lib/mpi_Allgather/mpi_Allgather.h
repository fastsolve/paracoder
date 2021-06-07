#ifndef MPI_ALLGATHER_H
#define MPI_ALLGATHER_H

#include "mpi_Allgather_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Allgather(const M2C_OpaquePtrType *sptr, int scount,
                          const M2C_OpaqueType *stype,
                          const M2C_OpaquePtrType *rptr, int rcount,
                          const M2C_OpaqueType *rtype,
                          const M2C_OpaqueType *comm, int *info,
                          boolean_T *toplevel);

extern void mpi_Allgather_initialize(void);

extern void mpi_Allgather_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
