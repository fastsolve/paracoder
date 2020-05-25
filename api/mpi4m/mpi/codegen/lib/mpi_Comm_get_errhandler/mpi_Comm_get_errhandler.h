#ifndef MPI_COMM_GET_ERRHANDLER_H
#define MPI_COMM_GET_ERRHANDLER_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_get_errhandler_types.h"

extern void mpi_Comm_get_errhandler(const struct0_T *comm, struct0_T *errhandler,
  int *info, boolean_T *toplevel);
extern void mpi_Comm_get_errhandler_initialize(void);
extern void mpi_Comm_get_errhandler_terminate(void);

#endif
