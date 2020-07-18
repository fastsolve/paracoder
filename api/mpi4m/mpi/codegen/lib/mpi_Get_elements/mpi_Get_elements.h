#ifndef MPI_GET_ELEMENTS_H
#define MPI_GET_ELEMENTS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Get_elements_types.h"

extern void mpi_Get_elements(const M2C_OpaqueType *stat, const M2C_OpaqueType
  *datatype, int *elems, int *info, boolean_T *toplevel);
extern void mpi_Get_elements_initialize(void);
extern void mpi_Get_elements_terminate(void);

#endif
