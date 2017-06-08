#ifndef MPI_GET_CONST_H
#define MPI_GET_CONST_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_get_const_types.h"

extern void mpi_get_const(const emxArray_char_T *name, struct0_T *obj);
extern void mpi_get_const_initialize(void);
extern void mpi_get_const_terminate(void);

#endif
