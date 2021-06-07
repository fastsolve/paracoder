#ifndef MPI_COMM_SPLIT_H
#define MPI_COMM_SPLIT_H

#include "mpi_Comm_split_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_split(const M2C_OpaqueType *comm, int color, int key,
                           M2C_OpaqueType *newcomm, int *info,
                           boolean_T *toplevel);

extern void mpi_Comm_split_initialize(void);

extern void mpi_Comm_split_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
