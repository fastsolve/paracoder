#ifndef MPI_SEND_INIT_H
#define MPI_SEND_INIT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Send_init_types.h"

extern void mpi_Send_init(const M2C_OpaquePtrType *ptr, int count, const
  M2C_OpaqueType *datatype, int dest, int tag, const M2C_OpaqueType *comm,
  M2C_OpaqueType *req, int *info, boolean_T *toplevel);
extern void mpi_Send_init_initialize(void);
extern void mpi_Send_init_terminate(void);

#endif
