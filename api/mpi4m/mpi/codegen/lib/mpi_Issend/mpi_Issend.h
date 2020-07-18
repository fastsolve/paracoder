#ifndef MPI_ISSEND_H
#define MPI_ISSEND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Issend_types.h"

extern void mpi_Issend(const M2C_OpaquePtrType *ptr, int count, const
  M2C_OpaqueType *datatype, int dest, int tag, const M2C_OpaqueType *comm,
  M2C_OpaqueType *req, int *info, boolean_T *toplevel);
extern void mpi_Issend_initialize(void);
extern void mpi_Issend_terminate(void);

#endif
