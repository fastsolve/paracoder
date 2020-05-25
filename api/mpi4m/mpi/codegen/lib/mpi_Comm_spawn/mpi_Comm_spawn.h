#ifndef MPI_COMM_SPAWN_H
#define MPI_COMM_SPAWN_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Comm_spawn_types.h"

extern void mpi_Comm_spawn(const emxArray_char_T *command, const struct0_T *argv,
  int maxprocs, const struct0_T *mpiinfo, int root, const struct0_T *comm,
  struct0_T *intercomm, emxArray_int32_T *errcodes, int *info, boolean_T
  *toplevel);
extern void mpi_Comm_spawn_initialize(void);
extern void mpi_Comm_spawn_terminate(void);

#endif
