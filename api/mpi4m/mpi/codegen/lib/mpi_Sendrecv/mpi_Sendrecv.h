#ifndef MPI_SENDRECV_H
#define MPI_SENDRECV_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Sendrecv_types.h"

extern void mpi_Sendrecv(const struct0_T *sptr, int scount, const struct1_T
  *stype, int dst, int stag, const struct0_T *rptr, int rcount, const struct1_T *
  rtype, int src, int rtag, const struct1_T *comm, struct1_T *stat, int *info,
  boolean_T *toplevel);
extern void mpi_Sendrecv_initialize(void);
extern void mpi_Sendrecv_terminate(void);

#endif
