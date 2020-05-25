#ifndef MPI_PCONTROL_H
#define MPI_PCONTROL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Pcontrol_types.h"

extern void mpi_Pcontrol(int level, int *info, boolean_T *toplevel);
extern void mpi_Pcontrol_initialize(void);
extern void mpi_Pcontrol_terminate(void);

#endif
