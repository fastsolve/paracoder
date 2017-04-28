#ifndef MPI_WAIT_H
#define MPI_WAIT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Wait_types.h"

extern void mpi_Wait(struct0_T *req, struct0_T *stat, int *info, boolean_T
                     *toplevel);
extern void mpi_Wait_initialize(void);
extern void mpi_Wait_terminate(void);

#endif
