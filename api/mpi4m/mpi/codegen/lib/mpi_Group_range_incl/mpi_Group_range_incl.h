#ifndef MPI_GROUP_RANGE_INCL_H
#define MPI_GROUP_RANGE_INCL_H

#include "mpi_Group_range_incl_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Group_range_incl(const M2C_OpaqueType *group, int n,
                                 const emxArray_int32_T *ranges,
                                 M2C_OpaqueType *newgroup, int *info,
                                 boolean_T *toplevel);

extern void mpi_Group_range_incl_initialize(void);

extern void mpi_Group_range_incl_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
