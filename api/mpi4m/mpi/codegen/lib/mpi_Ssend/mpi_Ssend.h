#ifndef MPI_SSEND_H
#define MPI_SSEND_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Ssend_types.h"

extern void mpi_Ssend(const struct0_T *ptr, int count, const struct1_T *datatype,
                      int dest, int tag, const struct1_T *comm, int *info,
                      boolean_T *toplevel);
extern void mpi_Ssend_initialize(void);
extern void mpi_Ssend_terminate(void);

#endif
