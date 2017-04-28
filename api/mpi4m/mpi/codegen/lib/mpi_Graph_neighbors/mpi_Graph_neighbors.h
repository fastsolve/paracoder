#ifndef MPI_GRAPH_NEIGHBORS_H
#define MPI_GRAPH_NEIGHBORS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Graph_neighbors_types.h"

extern void mpi_Graph_neighbors(const struct0_T *comm, int rank, int
  maxneighbors, emxArray_int32_T *neighbors, int *info, boolean_T *toplevel);
extern void mpi_Graph_neighbors_initialize(void);
extern void mpi_Graph_neighbors_terminate(void);

#endif
