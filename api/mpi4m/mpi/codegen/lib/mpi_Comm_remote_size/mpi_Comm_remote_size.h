#ifndef MPI_COMM_REMOTE_SIZE_H
#define MPI_COMM_REMOTE_SIZE_H

#include "mpi_Comm_remote_size_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_remote_size(const M2C_OpaqueType *comm, int *size,
                                 int *info, boolean_T *toplevel);

extern void mpi_Comm_remote_size_initialize(void);

extern void mpi_Comm_remote_size_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
