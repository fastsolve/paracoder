#ifndef MPI_IRSEND_H
#define MPI_IRSEND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Irsend_types.h"

extern void mpi_Irsend(const struct0_T *ptr, int count, const struct1_T
  *datatype, int dest, int tag, const struct1_T *comm, struct1_T *req, int *info,
  boolean_T *toplevel);
extern void mpi_Irsend_initialize(void);
extern void mpi_Irsend_terminate(void);

#endif
