#ifndef MPI_SENDRECV_REPLACE_H
#define MPI_SENDRECV_REPLACE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Sendrecv_replace_types.h"

extern void mpi_Sendrecv_replace(const M2C_OpaquePtrType *ptr, int count, const
  M2C_OpaqueType *datatype, int dst, int stag, int src, int rtag, const
  M2C_OpaqueType *comm, M2C_OpaqueType *stat, int *info, boolean_T *toplevel);
extern void mpi_Sendrecv_replace_initialize(void);
extern void mpi_Sendrecv_replace_terminate(void);

#endif
