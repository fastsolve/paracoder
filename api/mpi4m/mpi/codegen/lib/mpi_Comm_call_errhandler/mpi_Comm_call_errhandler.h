#ifndef MPI_COMM_CALL_ERRHANDLER_H
#define MPI_COMM_CALL_ERRHANDLER_H

#include "mpi_Comm_call_errhandler_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_call_errhandler(const M2C_OpaqueType *comm, int errorcode,
                                     int *info, boolean_T *toplevel);

extern void mpi_Comm_call_errhandler_initialize(void);

extern void mpi_Comm_call_errhandler_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
