#ifndef MPI_GROUP_RANGE_EXCL_H
#define MPI_GROUP_RANGE_EXCL_H

#include "mpi_Group_range_excl_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Group_range_excl(const M2C_OpaqueType *group, int n,
                                 const emxArray_int32_T *ranges,
                                 M2C_OpaqueType *newgroup, int *info,
                                 boolean_T *toplevel);

extern void mpi_Group_range_excl_initialize(void);

extern void mpi_Group_range_excl_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
