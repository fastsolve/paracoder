#ifndef MPI_TESTALL_H
#define MPI_TESTALL_H

#include "mpi_Testall_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Testall(int count, M2C_OpaqueType *reqs, int *flag,
                        M2C_OpaqueType *stats, int *info, boolean_T *toplevel);

extern void mpi_Testall_initialize(void);

extern void mpi_Testall_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
