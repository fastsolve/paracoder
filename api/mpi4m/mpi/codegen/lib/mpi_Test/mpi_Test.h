#ifndef MPI_TEST_H
#define MPI_TEST_H

#include "mpi_Test_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Test(M2C_OpaqueType *req, int *flag, M2C_OpaqueType *stat,
                     int *info, boolean_T *toplevel);

extern void mpi_Test_initialize(void);

extern void mpi_Test_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
