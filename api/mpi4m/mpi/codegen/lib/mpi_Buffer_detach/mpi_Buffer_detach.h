#ifndef MPI_BUFFER_DETACH_H
#define MPI_BUFFER_DETACH_H

#include "mpi_Buffer_detach_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Buffer_detach(struct0_T *ptr, int *size, int *info,
                              boolean_T *toplevel);

extern void mpi_Buffer_detach_initialize(void);

extern void mpi_Buffer_detach_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
