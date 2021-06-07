#ifndef MPI_INIT_H
#define MPI_INIT_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Init(int *info, boolean_T *toplevel);

extern void mpi_Init_initialize(void);

extern void mpi_Init_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
