#ifndef MPI_REDUCE_H
#define MPI_REDUCE_H

#include "mpi_Reduce_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Reduce(const M2C_OpaquePtrType *sptr,
                       const M2C_OpaquePtrType *rptr, int count,
                       const M2C_OpaqueType *datatype, const M2C_OpaqueType *op,
                       int root, const M2C_OpaqueType *comm, int *info,
                       boolean_T *toplevel);

extern void mpi_Reduce_initialize(void);

extern void mpi_Reduce_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
