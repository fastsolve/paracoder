#ifndef MPI_RSEND_INIT_H
#define MPI_RSEND_INIT_H

#include "mpi_Rsend_init_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Rsend_init(const M2C_OpaquePtrType *ptr, int count,
                           const M2C_OpaqueType *datatype, int dest, int tag,
                           const M2C_OpaqueType *comm, M2C_OpaqueType *req,
                           int *info, boolean_T *toplevel);

extern void mpi_Rsend_init_initialize(void);

extern void mpi_Rsend_init_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
