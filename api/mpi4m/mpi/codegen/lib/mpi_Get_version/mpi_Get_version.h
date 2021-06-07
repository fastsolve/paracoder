#ifndef MPI_GET_VERSION_H
#define MPI_GET_VERSION_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Get_version(int *version, int *subversion, int *info,
                            boolean_T *toplevel);

extern void mpi_Get_version_initialize(void);

extern void mpi_Get_version_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
