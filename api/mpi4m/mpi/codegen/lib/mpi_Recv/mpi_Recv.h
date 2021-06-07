#ifndef MPI_RECV_H
#define MPI_RECV_H

#include "mpi_Recv_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Recv(const M2C_OpaquePtrType *ptr, int count,
                     const M2C_OpaqueType *datatype, int src, int tag,
                     const M2C_OpaqueType *comm, M2C_OpaqueType *stat,
                     int *info, boolean_T *toplevel);

extern void mpi_Recv_initialize(void);

extern void mpi_Recv_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
