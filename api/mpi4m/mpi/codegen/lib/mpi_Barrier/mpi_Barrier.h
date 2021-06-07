#ifndef MPI_BARRIER_H
#define MPI_BARRIER_H

#include "mpi_Barrier_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Barrier(const M2C_OpaqueType *comm, int *info,
                        boolean_T *toplevel);

extern void mpi_Barrier_initialize(void);

extern void mpi_Barrier_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
