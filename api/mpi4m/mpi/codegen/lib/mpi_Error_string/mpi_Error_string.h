#ifndef MPI_ERROR_STRING_H
#define MPI_ERROR_STRING_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Error_string_types.h"

extern void mpi_Error_string(int errcode, emxArray_char_T *msg, int *info,
  boolean_T *toplevel);
extern void mpi_Error_string_initialize(void);
extern void mpi_Error_string_terminate(void);

#endif
