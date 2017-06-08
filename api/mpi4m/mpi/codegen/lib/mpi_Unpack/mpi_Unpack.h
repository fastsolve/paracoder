#ifndef MPI_UNPACK_H
#define MPI_UNPACK_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Unpack_types.h"

extern void mpi_Unpack(const struct0_T *inbuf, int incount, int *position, const
  struct0_T *outbuf, int packsize, const struct1_T *datatype, const struct1_T
  *comm, int *info, boolean_T *toplevel);
extern void mpi_Unpack_initialize(void);
extern void mpi_Unpack_terminate(void);

#endif
