#ifndef MPI_OP_FREE_H
#define MPI_OP_FREE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Op_free_types.h"

extern void mpi_Op_free(struct0_T *op, int *info, boolean_T *toplevel);
extern void mpi_Op_free_initialize(void);
extern void mpi_Op_free_terminate(void);

#endif
