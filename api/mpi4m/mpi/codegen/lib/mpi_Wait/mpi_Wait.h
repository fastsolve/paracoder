#ifndef MPI_WAIT_H
#define MPI_WAIT_H

#include "mpi_Wait_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Wait(M2C_OpaqueType *req, M2C_OpaqueType *stat, int *info,
                     boolean_T *toplevel);

extern void mpi_Wait_initialize(void);

extern void mpi_Wait_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
