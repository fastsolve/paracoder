#ifndef MPI_GROUP_EXCL_H
#define MPI_GROUP_EXCL_H

#include "mpi_Group_excl_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Group_excl(const M2C_OpaqueType *group, int n,
                           const emxArray_int32_T *ranks,
                           M2C_OpaqueType *newgroup, int *info,
                           boolean_T *toplevel);

extern void mpi_Group_excl_initialize(void);

extern void mpi_Group_excl_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
