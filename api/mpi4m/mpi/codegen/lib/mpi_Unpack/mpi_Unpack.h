#ifndef MPI_UNPACK_H
#define MPI_UNPACK_H

#include "mpi_Unpack_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Unpack(const M2C_OpaquePtrType *inbuf, int incount,
                       int *position, const M2C_OpaquePtrType *outbuf,
                       int packsize, const M2C_OpaqueType *datatype,
                       const M2C_OpaqueType *comm, int *info,
                       boolean_T *toplevel);

extern void mpi_Unpack_initialize(void);

extern void mpi_Unpack_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
