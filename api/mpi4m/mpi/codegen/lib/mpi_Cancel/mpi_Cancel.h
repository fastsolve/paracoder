#ifndef MPI_CANCEL_H
#define MPI_CANCEL_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Cancel_types.h"

extern void mpi_Cancel(const struct0_T *req, int *info, boolean_T *toplevel);
extern void mpi_Cancel_initialize(void);
extern void mpi_Cancel_terminate(void);

#endif
