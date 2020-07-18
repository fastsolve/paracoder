#ifndef MPI_COMM_COMPARE_H
#define MPI_COMM_COMPARE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_compare_types.h"

extern void mpi_Comm_compare(const M2C_OpaqueType *comm1, const M2C_OpaqueType
  *comm2, int *result, int *info, boolean_T *toplevel);
extern void mpi_Comm_compare_initialize(void);
extern void mpi_Comm_compare_terminate(void);

#endif
