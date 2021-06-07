#ifndef MPI_GROUP_DIFFERENCE_H
#define MPI_GROUP_DIFFERENCE_H

#include "mpi_Group_difference_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Group_difference(const M2C_OpaqueType *group1,
                                 const M2C_OpaqueType *group2,
                                 M2C_OpaqueType *newgroup, int *info,
                                 boolean_T *toplevel);

extern void mpi_Group_difference_initialize(void);

extern void mpi_Group_difference_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
