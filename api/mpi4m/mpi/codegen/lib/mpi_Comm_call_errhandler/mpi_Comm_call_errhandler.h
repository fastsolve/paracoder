#ifndef MPI_COMM_CALL_ERRHANDLER_H
#define MPI_COMM_CALL_ERRHANDLER_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_call_errhandler_types.h"

extern void mpi_Comm_call_errhandler(const struct0_T *comm, int errorcode, int
  *info, boolean_T *toplevel);
extern void mpi_Comm_call_errhandler_initialize(void);
extern void mpi_Comm_call_errhandler_terminate(void);

#endif
