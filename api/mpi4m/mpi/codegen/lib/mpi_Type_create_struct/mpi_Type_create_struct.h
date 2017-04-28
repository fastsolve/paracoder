#ifndef MPI_TYPE_CREATE_STRUCT_H
#define MPI_TYPE_CREATE_STRUCT_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Type_create_struct_types.h"

extern void mpi_Type_create_struct(int count, const emxArray_int32_T *blocklens,
  const struct0_T *indices, const struct0_T *oldtypes, struct0_T *newtype, int
  *info, boolean_T *toplevel);
extern void mpi_Type_create_struct_initialize(void);
extern void mpi_Type_create_struct_terminate(void);

#endif
