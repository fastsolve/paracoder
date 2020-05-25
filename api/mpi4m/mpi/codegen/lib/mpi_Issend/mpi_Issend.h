#ifndef MPI_ISSEND_H
#define MPI_ISSEND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Issend_types.h"

extern void mpi_Issend(const struct0_T *ptr, int count, const struct1_T
  *datatype, int dest, int tag, const struct1_T *comm, struct1_T *req, int *info,
  boolean_T *toplevel);
extern void mpi_Issend_initialize(void);
extern void mpi_Issend_terminate(void);

#endif
