#ifndef MPI_GRAPH_NEIGHBORS_COUNT_H
#define MPI_GRAPH_NEIGHBORS_COUNT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Graph_neighbors_count_types.h"

extern void mpi_Graph_neighbors_count(const struct0_T *comm, int rank, int
  *nneighbors, int *info, boolean_T *toplevel);
extern void mpi_Graph_neighbors_count_initialize(void);
extern void mpi_Graph_neighbors_count_terminate(void);

#endif
