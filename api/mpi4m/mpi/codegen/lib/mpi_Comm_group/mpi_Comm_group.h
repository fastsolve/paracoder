#ifndef MPI_COMM_GROUP_H
#define MPI_COMM_GROUP_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_group_types.h"

extern void mpi_Comm_group(const M2C_OpaqueType *comm, M2C_OpaqueType *group,
  int *info, boolean_T *toplevel);
extern void mpi_Comm_group_initialize(void);
extern void mpi_Comm_group_terminate(void);

#endif
