#ifndef MPI_COMM_COMPARE_H
#define MPI_COMM_COMPARE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Comm_compare_types.h"

extern void mpi_Comm_compare(const struct0_T *comm1, const struct0_T *comm2, int
  *result, int *info, boolean_T *toplevel);
extern void mpi_Comm_compare_initialize(void);
extern void mpi_Comm_compare_terminate(void);

#endif
