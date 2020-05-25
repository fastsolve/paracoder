#ifndef MPI_COMM_CREATE_H
#define MPI_COMM_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_create_types.h"

extern void mpi_Comm_create(const struct0_T *comm, const struct0_T *group,
  struct0_T *newcomm, int *info, boolean_T *toplevel);
extern void mpi_Comm_create_initialize(void);
extern void mpi_Comm_create_terminate(void);

#endif
