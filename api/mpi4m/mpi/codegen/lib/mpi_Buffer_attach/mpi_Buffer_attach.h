#ifndef MPI_BUFFER_ATTACH_H
#define MPI_BUFFER_ATTACH_H

#include "mpi_Buffer_attach_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Buffer_attach(const M2C_OpaquePtrType *ptr, int size, int *info,
                              boolean_T *toplevel);

extern void mpi_Buffer_attach_initialize(void);

extern void mpi_Buffer_attach_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
