#ifndef MPI_BSEND_H
#define MPI_BSEND_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Bsend_types.h"

extern void mpi_Bsend(const struct0_T *ptr, int count, const struct1_T *datatype,
                      int dest, int tag, const struct1_T *comm, int *info,
                      boolean_T *toplevel);
extern void mpi_Bsend_initialize(void);
extern void mpi_Bsend_terminate(void);

#endif
