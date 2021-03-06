#ifndef MPI_GROUP_UNION_H
#define MPI_GROUP_UNION_H

#include "mpi_Group_union_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Group_union(const M2C_OpaqueType *group1,
                            const M2C_OpaqueType *group2,
                            M2C_OpaqueType *newgroup, int *info,
                            boolean_T *toplevel);

extern void mpi_Group_union_initialize(void);

extern void mpi_Group_union_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
