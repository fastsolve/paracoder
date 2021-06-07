#ifndef MPI_CARTDIM_GET_H
#define MPI_CARTDIM_GET_H

#include "mpi_Cartdim_get_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Cartdim_get(const M2C_OpaqueType *comm, int *ndims, int *info,
                            boolean_T *toplevel);

extern void mpi_Cartdim_get_initialize(void);

extern void mpi_Cartdim_get_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
