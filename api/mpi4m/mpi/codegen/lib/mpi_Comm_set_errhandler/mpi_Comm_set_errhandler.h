#ifndef MPI_COMM_SET_ERRHANDLER_H
#define MPI_COMM_SET_ERRHANDLER_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_set_errhandler_types.h"

extern void mpi_Comm_set_errhandler(const struct0_T *comm, const struct0_T
  *errhandler, int *info, boolean_T *toplevel);
extern void mpi_Comm_set_errhandler_initialize(void);
extern void mpi_Comm_set_errhandler_terminate(void);

#endif
