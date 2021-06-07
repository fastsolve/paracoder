#ifndef MPI_START_H
#define MPI_START_H

#include "mpi_Start_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Start(const M2C_OpaqueType *req, int *info,
                      boolean_T *toplevel);

extern void mpi_Start_initialize(void);

extern void mpi_Start_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
