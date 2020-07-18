#ifndef MPI_TEST_CANCELLED_H
#define MPI_TEST_CANCELLED_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Test_cancelled_types.h"

extern void mpi_Test_cancelled(const M2C_OpaqueType *stat, int *flag, int *info,
  boolean_T *toplevel);
extern void mpi_Test_cancelled_initialize(void);
extern void mpi_Test_cancelled_terminate(void);

#endif
