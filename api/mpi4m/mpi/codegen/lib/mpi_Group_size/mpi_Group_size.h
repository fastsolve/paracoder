#ifndef MPI_GROUP_SIZE_H
#define MPI_GROUP_SIZE_H

#include "mpi_Group_size_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Group_size(const M2C_OpaqueType *group, int *size, int *info,
                           boolean_T *toplevel);

extern void mpi_Group_size_initialize(void);

extern void mpi_Group_size_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
