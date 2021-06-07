#ifndef MPI_COMM_SPAWN_H
#define MPI_COMM_SPAWN_H

#include "mpi_Comm_spawn_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void
mpi_Comm_spawn(const emxArray_char_T *command, const M2C_OpaqueType *argv,
               int maxprocs, const M2C_OpaqueType *mpiinfo, int root,
               const M2C_OpaqueType *comm, M2C_OpaqueType *intercomm,
               emxArray_int32_T *errcodes, int *info, boolean_T *toplevel);

extern void mpi_Comm_spawn_initialize(void);

extern void mpi_Comm_spawn_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
