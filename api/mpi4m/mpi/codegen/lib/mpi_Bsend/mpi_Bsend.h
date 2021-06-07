#ifndef MPI_BSEND_H
#define MPI_BSEND_H

#include "mpi_Bsend_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Bsend(const M2C_OpaquePtrType *ptr, int count,
                      const M2C_OpaqueType *datatype, int dest, int tag,
                      const M2C_OpaqueType *comm, int *info,
                      boolean_T *toplevel);

extern void mpi_Bsend_initialize(void);

extern void mpi_Bsend_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
