#ifndef MPI_BCAST_H
#define MPI_BCAST_H

#include "mpi_Bcast_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Bcast(const M2C_OpaquePtrType *ptr, int count,
                      const M2C_OpaqueType *datatype, int root,
                      const M2C_OpaqueType *comm, int *info,
                      boolean_T *toplevel);

extern void mpi_Bcast_initialize(void);

extern void mpi_Bcast_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
