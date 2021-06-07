#ifndef MPI_TYPE_COMMIT_H
#define MPI_TYPE_COMMIT_H

#include "mpi_Type_commit_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Type_commit(M2C_OpaqueType *datatype, int *info,
                            boolean_T *toplevel);

extern void mpi_Type_commit_initialize(void);

extern void mpi_Type_commit_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
