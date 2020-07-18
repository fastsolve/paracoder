#ifndef MPI_IRSEND_H
#define MPI_IRSEND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Irsend_types.h"

extern void mpi_Irsend(const M2C_OpaquePtrType *ptr, int count, const
  M2C_OpaqueType *datatype, int dest, int tag, const M2C_OpaqueType *comm,
  M2C_OpaqueType *req, int *info, boolean_T *toplevel);
extern void mpi_Irsend_initialize(void);
extern void mpi_Irsend_terminate(void);

#endif
