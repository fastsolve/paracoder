#ifndef MPI_TESTSOME_H
#define MPI_TESTSOME_H

#include "mpi_Testsome_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Testsome(int count, M2C_OpaqueType *reqs,
                         emxArray_int32_T *idxs, M2C_OpaqueType *stats,
                         int *info, boolean_T *toplevel);

extern void mpi_Testsome_initialize(void);

extern void mpi_Testsome_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
