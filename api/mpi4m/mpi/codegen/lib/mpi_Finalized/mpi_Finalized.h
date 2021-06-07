#ifndef MPI_FINALIZED_H
#define MPI_FINALIZED_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Finalized(int *flag, int *info, boolean_T *toplevel);

extern void mpi_Finalized_initialize(void);

extern void mpi_Finalized_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
