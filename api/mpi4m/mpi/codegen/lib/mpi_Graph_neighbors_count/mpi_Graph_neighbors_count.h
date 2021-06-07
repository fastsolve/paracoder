#ifndef MPI_GRAPH_NEIGHBORS_COUNT_H
#define MPI_GRAPH_NEIGHBORS_COUNT_H

#include "mpi_Graph_neighbors_count_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Graph_neighbors_count(const M2C_OpaqueType *comm, int rank,
                                      int *nneighbors, int *info,
                                      boolean_T *toplevel);

extern void mpi_Graph_neighbors_count_initialize(void);

extern void mpi_Graph_neighbors_count_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
