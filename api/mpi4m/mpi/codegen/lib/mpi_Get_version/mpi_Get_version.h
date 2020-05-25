#ifndef MPI_GET_VERSION_H
#define MPI_GET_VERSION_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Get_version_types.h"

extern void mpi_Get_version(int *version, int *subversion, int *info, boolean_T *
  toplevel);
extern void mpi_Get_version_initialize(void);
extern void mpi_Get_version_terminate(void);

#endif
