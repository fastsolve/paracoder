#ifndef MPI_SEND_H
#define MPI_SEND_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Send_types.h"

extern void mpi_Send(const struct0_T *ptr, int count, const struct1_T *datatype,
                     int dest, int tag, const struct1_T *comm, int *info,
                     boolean_T *toplevel);
extern void mpi_Send_initialize(void);
extern void mpi_Send_terminate(void);

#endif
