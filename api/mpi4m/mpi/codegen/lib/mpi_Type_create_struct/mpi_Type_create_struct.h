#ifndef MPI_TYPE_CREATE_STRUCT_H
#define MPI_TYPE_CREATE_STRUCT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Type_create_struct_types.h"

extern void mpi_Type_create_struct(int count, const emxArray_int32_T *blocklens,
  const M2C_OpaqueType *indices, const M2C_OpaqueType *oldtypes, M2C_OpaqueType *
  newtype, int *info, boolean_T *toplevel);
extern void mpi_Type_create_struct_initialize(void);
extern void mpi_Type_create_struct_terminate(void);

#endif
