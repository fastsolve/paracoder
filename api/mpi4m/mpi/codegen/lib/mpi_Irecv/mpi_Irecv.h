#ifndef MPI_IRECV_H
#define MPI_IRECV_H

#include "mpi_Irecv_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Irecv(const M2C_OpaquePtrType *ptr, int count,
                      const M2C_OpaqueType *datatype, int src, int tag,
                      const M2C_OpaqueType *comm, M2C_OpaqueType *req,
                      int *info, boolean_T *toplevel);

extern void mpi_Irecv_initialize(void);

extern void mpi_Irecv_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
