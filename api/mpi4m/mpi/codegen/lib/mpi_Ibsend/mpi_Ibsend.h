#ifndef MPI_IBSEND_H
#define MPI_IBSEND_H

#include "mpi_Ibsend_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Ibsend(const M2C_OpaquePtrType *ptr, int count,
                       const M2C_OpaqueType *datatype, int dest, int tag,
                       const M2C_OpaqueType *comm, M2C_OpaqueType *req,
                       int *info, boolean_T *toplevel);

extern void mpi_Ibsend_initialize(void);

extern void mpi_Ibsend_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
