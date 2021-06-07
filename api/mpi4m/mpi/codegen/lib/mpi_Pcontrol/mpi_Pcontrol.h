#ifndef MPI_PCONTROL_H
#define MPI_PCONTROL_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Pcontrol(int level, int *info, boolean_T *toplevel);

extern void mpi_Pcontrol_initialize(void);

extern void mpi_Pcontrol_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
