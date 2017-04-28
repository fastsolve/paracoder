#ifndef MPI_IRECV_H
#define MPI_IRECV_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Irecv_types.h"

extern void mpi_Irecv(const struct0_T *ptr, int count, const struct1_T *datatype,
                      int src, int tag, const struct1_T *comm, struct1_T *req,
                      int *info, boolean_T *toplevel);
extern void mpi_Irecv_initialize(void);
extern void mpi_Irecv_terminate(void);

#endif
