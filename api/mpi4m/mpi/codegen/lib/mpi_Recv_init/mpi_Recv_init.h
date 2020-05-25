#ifndef MPI_RECV_INIT_H
#define MPI_RECV_INIT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Recv_init_types.h"

extern void mpi_Recv_init(const struct0_T *ptr, int count, const struct1_T
  *datatype, int dest, int tag, const struct1_T *comm, struct1_T *req, int *info,
  boolean_T *toplevel);
extern void mpi_Recv_init_initialize(void);
extern void mpi_Recv_init_terminate(void);

#endif
