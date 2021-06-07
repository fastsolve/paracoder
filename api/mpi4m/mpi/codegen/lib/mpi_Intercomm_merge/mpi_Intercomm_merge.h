#ifndef MPI_INTERCOMM_MERGE_H
#define MPI_INTERCOMM_MERGE_H

#include "mpi_Intercomm_merge_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Intercomm_merge(const M2C_OpaqueType *intercomm, int high,
                                M2C_OpaqueType *newcomm, int *info,
                                boolean_T *toplevel);

extern void mpi_Intercomm_merge_initialize(void);

extern void mpi_Intercomm_merge_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
