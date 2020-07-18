#ifndef MPI_GRAPH_CREATE_H
#define MPI_GRAPH_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Graph_create_types.h"

extern void mpi_Graph_create(const M2C_OpaqueType *comm, int nnodes, const
  emxArray_int32_T *b_index, const emxArray_int32_T *edges, int reorder,
  M2C_OpaqueType *newcomm, int *info, boolean_T *toplevel);
extern void mpi_Graph_create_initialize(void);
extern void mpi_Graph_create_terminate(void);

#endif
