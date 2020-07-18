#ifndef MPI_SSEND_H
#define MPI_SSEND_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Ssend_types.h"

extern void mpi_Ssend(const M2C_OpaquePtrType *ptr, int count, const
                      M2C_OpaqueType *datatype, int dest, int tag, const
                      M2C_OpaqueType *comm, int *info, boolean_T *toplevel);
extern void mpi_Ssend_initialize(void);
extern void mpi_Ssend_terminate(void);

#endif
