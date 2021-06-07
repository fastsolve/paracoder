#ifndef MPI_GRAPH_NEIGHBORS_H
#define MPI_GRAPH_NEIGHBORS_H

#include "mpi_Graph_neighbors_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Graph_neighbors(const M2C_OpaqueType *comm, int rank,
                                int maxneighbors, emxArray_int32_T *neighbors,
                                int *info, boolean_T *toplevel);

extern void mpi_Graph_neighbors_initialize(void);

extern void mpi_Graph_neighbors_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
