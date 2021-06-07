#ifndef MPI_GRAPH_MAP_H
#define MPI_GRAPH_MAP_H

#include "mpi_Graph_map_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Graph_map(const M2C_OpaqueType *comm, int nnodes,
                          const emxArray_int32_T *b_index,
                          const emxArray_int32_T *edges, int *newrank,
                          int *info, boolean_T *toplevel);

extern void mpi_Graph_map_initialize(void);

extern void mpi_Graph_map_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
