#ifndef MPI_WAITALL_H
#define MPI_WAITALL_H

#include "mpi_Waitall_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Waitall(int count, M2C_OpaqueType *reqs, M2C_OpaqueType *stats,
                        int *info, boolean_T *toplevel);

extern void mpi_Waitall_initialize(void);

extern void mpi_Waitall_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
