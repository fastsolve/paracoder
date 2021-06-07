#ifndef MPI_COMM_COMPARE_H
#define MPI_COMM_COMPARE_H

#include "mpi_Comm_compare_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_compare(const M2C_OpaqueType *comm1,
                             const M2C_OpaqueType *comm2, int *result,
                             int *info, boolean_T *toplevel);

extern void mpi_Comm_compare_initialize(void);

extern void mpi_Comm_compare_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
