#ifndef MPI_COMM_DUP_H
#define MPI_COMM_DUP_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_dup_types.h"

extern void mpi_Comm_dup(const M2C_OpaqueType *comm, M2C_OpaqueType *dup, int
  *info, boolean_T *toplevel);
extern void mpi_Comm_dup_initialize(void);
extern void mpi_Comm_dup_terminate(void);

#endif
