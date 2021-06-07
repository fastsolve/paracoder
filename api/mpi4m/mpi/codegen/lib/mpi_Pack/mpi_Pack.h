#ifndef MPI_PACK_H
#define MPI_PACK_H

#include "mpi_Pack_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Pack(const M2C_OpaquePtrType *inbuf, int incount,
                     const M2C_OpaqueType *datatype,
                     const M2C_OpaquePtrType *outbuf, int outcount,
                     int *position, const M2C_OpaqueType *comm, int *info,
                     boolean_T *toplevel);

extern void mpi_Pack_initialize(void);

extern void mpi_Pack_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
