#ifndef MPI_RSEND_H
#define MPI_RSEND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Rsend_types.h"

extern void mpi_Rsend(const M2C_OpaquePtrType *ptr, int count, const
                      M2C_OpaqueType *datatype, int dest, int tag, const
                      M2C_OpaqueType *comm, int *info, boolean_T *toplevel);
extern void mpi_Rsend_initialize(void);
extern void mpi_Rsend_terminate(void);

#endif
