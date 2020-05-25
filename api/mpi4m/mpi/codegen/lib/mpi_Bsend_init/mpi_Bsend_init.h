#ifndef MPI_BSEND_INIT_H
#define MPI_BSEND_INIT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Bsend_init_types.h"

extern void mpi_Bsend_init(const struct0_T *ptr, int count, const struct1_T
  *datatype, int dest, int tag, const struct1_T *comm, struct1_T *req, int *info,
  boolean_T *toplevel);
extern void mpi_Bsend_init_initialize(void);
extern void mpi_Bsend_init_terminate(void);

#endif
