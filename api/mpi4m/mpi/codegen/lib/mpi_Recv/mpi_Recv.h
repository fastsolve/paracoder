#ifndef MPI_RECV_H
#define MPI_RECV_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Recv_types.h"

extern void mpi_Recv(const struct0_T *ptr, int count, const struct1_T *datatype,
                     int src, int tag, const struct1_T *comm, struct1_T *stat,
                     int *info, boolean_T *toplevel);
extern void mpi_Recv_initialize(void);
extern void mpi_Recv_terminate(void);

#endif
