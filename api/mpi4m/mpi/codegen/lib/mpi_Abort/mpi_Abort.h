#ifndef MPI_ABORT_H
#define MPI_ABORT_H

#include "mpi_Abort_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int mpi_Abort(const M2C_OpaqueType *comm, int errorcode);

extern void mpi_Abort_initialize(void);

extern void mpi_Abort_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
