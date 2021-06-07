#ifndef MPI_CANCEL_H
#define MPI_CANCEL_H

#include "mpi_Cancel_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Cancel(const M2C_OpaqueType *req, int *info,
                       boolean_T *toplevel);

extern void mpi_Cancel_initialize(void);

extern void mpi_Cancel_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
