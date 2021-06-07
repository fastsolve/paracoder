#ifndef MPI_COMM_FREE_H
#define MPI_COMM_FREE_H

#include "mpi_Comm_free_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_free(M2C_OpaqueType *comm, int *info, boolean_T *toplevel);

extern void mpi_Comm_free_initialize(void);

extern void mpi_Comm_free_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
