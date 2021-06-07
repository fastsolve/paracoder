#ifndef MPI_WTICK_H
#define MPI_WTICK_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern double mpi_Wtick(void);

extern void mpi_Wtick_initialize(void);

extern void mpi_Wtick_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
