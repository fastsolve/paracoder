#ifndef MPI_TEST_CANCELLED_H
#define MPI_TEST_CANCELLED_H

#include "mpi_Test_cancelled_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Test_cancelled(const M2C_OpaqueType *stat, int *flag, int *info,
                               boolean_T *toplevel);

extern void mpi_Test_cancelled_initialize(void);

extern void mpi_Test_cancelled_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
