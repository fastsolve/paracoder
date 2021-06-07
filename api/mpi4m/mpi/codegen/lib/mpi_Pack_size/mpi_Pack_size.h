#ifndef MPI_PACK_SIZE_H
#define MPI_PACK_SIZE_H

#include "mpi_Pack_size_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Pack_size(int count, const M2C_OpaqueType *datatype,
                          const M2C_OpaqueType *comm, int *size, int *info,
                          boolean_T *toplevel);

extern void mpi_Pack_size_initialize(void);

extern void mpi_Pack_size_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
