#ifndef MPI_SEND_H
#define MPI_SEND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Send_types.h"

extern void mpi_Send(const M2C_OpaquePtrType *ptr, int count, const
                     M2C_OpaqueType *datatype, int dest, int tag, const
                     M2C_OpaqueType *comm, int *info, boolean_T *toplevel);
extern void mpi_Send_initialize(void);
extern void mpi_Send_terminate(void);

#endif
