#ifndef MPI_FINALIZE_H
#define MPI_FINALIZE_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Finalize(int *info, boolean_T *toplevel);

extern void mpi_Finalize_initialize(void);

extern void mpi_Finalize_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
