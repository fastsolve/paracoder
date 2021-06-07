#ifndef MPI_GET_CONST_H
#define MPI_GET_CONST_H

#include "mpi_get_const_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_get_const(const emxArray_char_T *name, struct0_T *obj);

extern void mpi_get_const_initialize(void);

extern void mpi_get_const_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
