#ifndef MPI_IBSEND_H
#define MPI_IBSEND_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Ibsend_types.h"

extern void mpi_Ibsend(const struct0_T *ptr, int count, const struct1_T
  *datatype, int dest, int tag, const struct1_T *comm, struct1_T *req, int *info,
  boolean_T *toplevel);
extern void mpi_Ibsend_initialize(void);
extern void mpi_Ibsend_terminate(void);

#endif
