#ifndef MPI_COMM_FREE_H
#define MPI_COMM_FREE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Comm_free_types.h"

extern void mpi_Comm_free(struct0_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Comm_free_initialize(void);
extern void mpi_Comm_free_terminate(void);

#endif
