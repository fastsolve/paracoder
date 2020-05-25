#ifndef MPI_GRAPH_MAP_H
#define MPI_GRAPH_MAP_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Graph_map_types.h"

extern void mpi_Graph_map(const struct0_T *comm, int nnodes, const
  emxArray_int32_T *b_index, const emxArray_int32_T *edges, int *newrank, int
  *info, boolean_T *toplevel);
extern void mpi_Graph_map_initialize(void);
extern void mpi_Graph_map_terminate(void);

#endif
