#ifndef MPI_GRAPHDIMS_GET_H
#define MPI_GRAPHDIMS_GET_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Graphdims_get_types.h"

extern void mpi_Graphdims_get(const struct0_T *comm, int *nnodes, int *nedges,
  int *info, boolean_T *toplevel);
extern void mpi_Graphdims_get_initialize(void);
extern void mpi_Graphdims_get_terminate(void);

#endif
