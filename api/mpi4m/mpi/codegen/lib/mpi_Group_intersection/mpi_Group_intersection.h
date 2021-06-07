#ifndef MPI_GROUP_INTERSECTION_H
#define MPI_GROUP_INTERSECTION_H

#include "mpi_Group_intersection_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Group_intersection(const M2C_OpaqueType *group1,
                                   const M2C_OpaqueType *group2,
                                   M2C_OpaqueType *newgroup, int *info,
                                   boolean_T *toplevel);

extern void mpi_Group_intersection_initialize(void);

extern void mpi_Group_intersection_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
