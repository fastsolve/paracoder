#ifndef MPI_BCAST_H
#define MPI_BCAST_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Bcast_types.h"

extern void mpi_Bcast(const struct0_T *ptr, int count, const struct1_T *datatype,
                      int root, const struct1_T *comm, int *info, boolean_T
                      *toplevel);
extern void mpi_Bcast_initialize(void);
extern void mpi_Bcast_terminate(void);

#endif
