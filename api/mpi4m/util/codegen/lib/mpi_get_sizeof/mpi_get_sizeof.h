#ifndef MPI_GET_SIZEOF_H
#define MPI_GET_SIZEOF_H

#include "mpi_get_sizeof_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int mpi_get_sizeof(const emxArray_char_T *typename);

extern void mpi_get_sizeof_initialize(void);

extern void mpi_get_sizeof_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
