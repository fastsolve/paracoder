#ifndef MPI_COMM_REMOTE_GROUP_H
#define MPI_COMM_REMOTE_GROUP_H

#include "mpi_Comm_remote_group_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_remote_group(const M2C_OpaqueType *comm,
                                  M2C_OpaqueType *group, int *info,
                                  boolean_T *toplevel);

extern void mpi_Comm_remote_group_initialize(void);

extern void mpi_Comm_remote_group_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
