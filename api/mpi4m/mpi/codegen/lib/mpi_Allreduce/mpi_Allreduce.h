#ifndef MPI_ALLREDUCE_H
#define MPI_ALLREDUCE_H

#include "mpi_Allreduce_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Allreduce(const M2C_OpaquePtrType *sptr,
                          const M2C_OpaquePtrType *rptr, int count,
                          const M2C_OpaqueType *datatype,
                          const M2C_OpaqueType *op, const M2C_OpaqueType *comm,
                          int *info, boolean_T *toplevel);

extern void mpi_Allreduce_initialize(void);

extern void mpi_Allreduce_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
