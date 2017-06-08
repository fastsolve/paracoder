#ifndef MPI_RSEND_H
#define MPI_RSEND_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Rsend_types.h"

extern void mpi_Rsend(const struct0_T *ptr, int count, const struct1_T *datatype,
                      int dest, int tag, const struct1_T *comm, int *info,
                      boolean_T *toplevel);
extern void mpi_Rsend_initialize(void);
extern void mpi_Rsend_terminate(void);

#endif
