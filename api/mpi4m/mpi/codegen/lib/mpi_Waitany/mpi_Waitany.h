#ifndef MPI_WAITANY_H
#define MPI_WAITANY_H

#include "mpi_Waitany_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Waitany(int count, M2C_OpaqueType *reqs, int *idx,
                        M2C_OpaqueType *stat, int *info, boolean_T *toplevel);

extern void mpi_Waitany_initialize(void);

extern void mpi_Waitany_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
