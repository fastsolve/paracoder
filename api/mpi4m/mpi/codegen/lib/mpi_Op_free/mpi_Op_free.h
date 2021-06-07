#ifndef MPI_OP_FREE_H
#define MPI_OP_FREE_H

#include "mpi_Op_free_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Op_free(M2C_OpaqueType *op, int *info, boolean_T *toplevel);

extern void mpi_Op_free_initialize(void);

extern void mpi_Op_free_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
