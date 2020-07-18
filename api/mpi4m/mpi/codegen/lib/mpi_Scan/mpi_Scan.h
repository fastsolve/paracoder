#ifndef MPI_SCAN_H
#define MPI_SCAN_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Scan_types.h"

extern void mpi_Scan(const M2C_OpaquePtrType *sptr, const M2C_OpaquePtrType
                     *rptr, int count, const M2C_OpaqueType *datatype, const
                     M2C_OpaqueType *op, const M2C_OpaqueType *comm, int *info,
                     boolean_T *toplevel);
extern void mpi_Scan_initialize(void);
extern void mpi_Scan_terminate(void);

#endif
