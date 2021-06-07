#ifndef MPI_INITIALIZED_H
#define MPI_INITIALIZED_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Initialized(int *flag, int *info, boolean_T *toplevel);

extern void mpi_Initialized_initialize(void);

extern void mpi_Initialized_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
