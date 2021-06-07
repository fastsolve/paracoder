#ifndef MPI_TYPE_CREATE_HINDEXED_H
#define MPI_TYPE_CREATE_HINDEXED_H

#include "mpi_Type_create_hindexed_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Type_create_hindexed(int count,
                                     const emxArray_int32_T *blocklens,
                                     const M2C_OpaqueType *indices,
                                     const M2C_OpaqueType *oldtype,
                                     M2C_OpaqueType *newtype, int *info,
                                     boolean_T *toplevel);

extern void mpi_Type_create_hindexed_initialize(void);

extern void mpi_Type_create_hindexed_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
