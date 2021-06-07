#ifndef MPI_OP_CREATE_H
#define MPI_OP_CREATE_H

#include "mpi_Op_create_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Op_create(const M2C_OpaqueType *func, int commute,
                          M2C_OpaqueType *op, int *info, boolean_T *toplevel);

extern void mpi_Op_create_initialize(void);

extern void mpi_Op_create_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
