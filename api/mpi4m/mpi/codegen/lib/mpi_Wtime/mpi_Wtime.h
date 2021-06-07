#ifndef MPI_WTIME_H
#define MPI_WTIME_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern double mpi_Wtime(void);

extern void mpi_Wtime_initialize(void);

extern void mpi_Wtime_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
