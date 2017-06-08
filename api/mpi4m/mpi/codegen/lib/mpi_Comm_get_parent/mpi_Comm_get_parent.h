#ifndef MPI_COMM_GET_PARENT_H
#define MPI_COMM_GET_PARENT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Comm_get_parent_types.h"

extern void mpi_Comm_get_parent(struct0_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Comm_get_parent_initialize(void);
extern void mpi_Comm_get_parent_terminate(void);

#endif
