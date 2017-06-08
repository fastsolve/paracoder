#ifndef MPI_TYPE_VECTOR_H
#define MPI_TYPE_VECTOR_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Type_vector_types.h"

extern void mpi_Type_vector(int count, int blocklen, int stride, const struct0_T
  *oldtype, struct0_T *newtype, int *info, boolean_T *toplevel);
extern void mpi_Type_vector_initialize(void);
extern void mpi_Type_vector_terminate(void);

#endif
