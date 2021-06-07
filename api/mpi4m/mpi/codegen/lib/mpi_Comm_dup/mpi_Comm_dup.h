#ifndef MPI_COMM_DUP_H
#define MPI_COMM_DUP_H

#include "mpi_Comm_dup_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_dup(const M2C_OpaqueType *comm, M2C_OpaqueType *dup,
                         int *info, boolean_T *toplevel);

extern void mpi_Comm_dup_initialize(void);

extern void mpi_Comm_dup_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
