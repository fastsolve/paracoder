#ifndef MPI_ALLGATHER_H
#define MPI_ALLGATHER_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Allgather_types.h"

extern void mpi_Allgather(const M2C_OpaquePtrType *sptr, int scount, const
  M2C_OpaqueType *stype, const M2C_OpaquePtrType *rptr, int rcount, const
  M2C_OpaqueType *rtype, const M2C_OpaqueType *comm, int *info, boolean_T
  *toplevel);
extern void mpi_Allgather_initialize(void);
extern void mpi_Allgather_terminate(void);

#endif
