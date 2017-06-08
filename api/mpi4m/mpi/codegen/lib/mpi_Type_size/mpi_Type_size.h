#ifndef MPI_TYPE_SIZE_H
#define MPI_TYPE_SIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Type_size_types.h"

extern void mpi_Type_size(const struct0_T *datatype, int *size, int *info,
  boolean_T *toplevel);
extern void mpi_Type_size_initialize(void);
extern void mpi_Type_size_terminate(void);

#endif
