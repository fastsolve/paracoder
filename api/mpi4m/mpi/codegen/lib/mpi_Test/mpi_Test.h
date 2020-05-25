#ifndef MPI_TEST_H
#define MPI_TEST_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Test_types.h"

extern void mpi_Test(struct0_T *req, int *flag, struct0_T *stat, int *info,
                     boolean_T *toplevel);
extern void mpi_Test_initialize(void);
extern void mpi_Test_terminate(void);

#endif
