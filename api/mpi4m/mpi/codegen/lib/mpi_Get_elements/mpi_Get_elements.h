#ifndef MPI_GET_ELEMENTS_H
#define MPI_GET_ELEMENTS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Get_elements_types.h"

extern void mpi_Get_elements(const struct0_T *stat, const struct0_T *datatype,
  int *elems, int *info, boolean_T *toplevel);
extern void mpi_Get_elements_initialize(void);
extern void mpi_Get_elements_terminate(void);

#endif
