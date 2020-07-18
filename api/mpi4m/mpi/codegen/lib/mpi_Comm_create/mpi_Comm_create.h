#ifndef MPI_COMM_CREATE_H
#define MPI_COMM_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_create_types.h"

extern void mpi_Comm_create(const M2C_OpaqueType *comm, const M2C_OpaqueType
  *group, M2C_OpaqueType *newcomm, int *info, boolean_T *toplevel);
extern void mpi_Comm_create_initialize(void);
extern void mpi_Comm_create_terminate(void);

#endif
