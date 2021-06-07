#ifndef MPI_GROUP_RANK_H
#define MPI_GROUP_RANK_H

#include "mpi_Group_rank_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Group_rank(const M2C_OpaqueType *group, int *rank, int *info,
                           boolean_T *toplevel);

extern void mpi_Group_rank_initialize(void);

extern void mpi_Group_rank_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
