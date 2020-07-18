#ifndef MPI_TYPE_COMMIT_H
#define MPI_TYPE_COMMIT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Type_commit_types.h"

extern void mpi_Type_commit(M2C_OpaqueType *datatype, int *info, boolean_T
  *toplevel);
extern void mpi_Type_commit_initialize(void);
extern void mpi_Type_commit_terminate(void);

#endif
