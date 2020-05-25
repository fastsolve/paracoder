#ifndef MPI_COMM_SPLIT_H
#define MPI_COMM_SPLIT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_split_types.h"

extern void mpi_Comm_split(const struct0_T *comm, int color, int key, struct0_T *
  newcomm, int *info, boolean_T *toplevel);
extern void mpi_Comm_split_initialize(void);
extern void mpi_Comm_split_terminate(void);

#endif
