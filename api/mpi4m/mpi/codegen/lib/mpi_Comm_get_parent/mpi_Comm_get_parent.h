#ifndef MPI_COMM_GET_PARENT_H
#define MPI_COMM_GET_PARENT_H

#include "mpi_Comm_get_parent_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Comm_get_parent(struct0_T *comm, int *info,
                                boolean_T *toplevel);

extern void mpi_Comm_get_parent_initialize(void);

extern void mpi_Comm_get_parent_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
