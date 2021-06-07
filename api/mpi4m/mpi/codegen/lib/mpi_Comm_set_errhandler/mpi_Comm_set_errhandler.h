#ifndef MPI_COMM_SET_ERRHANDLER_H
#define MPI_COMM_SET_ERRHANDLER_H

#include "mpi_Comm_set_errhandler_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_set_errhandler(const M2C_OpaqueType *comm,
                                    const M2C_OpaqueType *errhandler, int *info,
                                    boolean_T *toplevel);

extern void mpi_Comm_set_errhandler_initialize(void);

extern void mpi_Comm_set_errhandler_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
