#ifndef MPI_COMM_RANK_H
#define MPI_COMM_RANK_H

#include "mpi_Comm_rank_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_rank(const M2C_OpaqueType *comm, int *rank, int *info,
                          boolean_T *toplevel);

extern void mpi_Comm_rank_initialize(void);

extern void mpi_Comm_rank_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
