#ifndef MPI_ISEND_H
#define MPI_ISEND_H

#include "mpi_Isend_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Isend(const M2C_OpaquePtrType *ptr, int count,
                      const M2C_OpaqueType *datatype, int dest, int tag,
                      const M2C_OpaqueType *comm, M2C_OpaqueType *req,
                      int *info, boolean_T *toplevel);

extern void mpi_Isend_initialize(void);

extern void mpi_Isend_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
