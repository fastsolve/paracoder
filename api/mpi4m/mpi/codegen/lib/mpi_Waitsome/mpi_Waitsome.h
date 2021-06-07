#ifndef MPI_WAITSOME_H
#define MPI_WAITSOME_H

#include "mpi_Waitsome_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Waitsome(int count, M2C_OpaqueType *reqs,
                         emxArray_int32_T *idxs, M2C_OpaqueType *stats,
                         int *info, boolean_T *toplevel);

extern void mpi_Waitsome_initialize(void);

extern void mpi_Waitsome_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
