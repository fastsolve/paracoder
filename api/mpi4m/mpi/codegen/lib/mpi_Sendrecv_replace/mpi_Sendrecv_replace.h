#ifndef MPI_SENDRECV_REPLACE_H
#define MPI_SENDRECV_REPLACE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Sendrecv_replace_types.h"

extern void mpi_Sendrecv_replace(const struct0_T *ptr, int count, const
  struct1_T *datatype, int dst, int stag, int src, int rtag, const struct1_T
  *comm, struct1_T *stat, int *info, boolean_T *toplevel);
extern void mpi_Sendrecv_replace_initialize(void);
extern void mpi_Sendrecv_replace_terminate(void);

#endif
