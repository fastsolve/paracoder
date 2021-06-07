#ifndef MPI_ERROR_STRING_H
#define MPI_ERROR_STRING_H

#include "mpi_Error_string_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Error_string(int errcode, emxArray_char_T *msg, int *info,
                             boolean_T *toplevel);

extern void mpi_Error_string_initialize(void);

extern void mpi_Error_string_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
