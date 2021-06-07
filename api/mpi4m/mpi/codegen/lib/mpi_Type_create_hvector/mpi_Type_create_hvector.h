#ifndef MPI_TYPE_CREATE_HVECTOR_H
#define MPI_TYPE_CREATE_HVECTOR_H

#include "mpi_Type_create_hvector_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Type_create_hvector(int count, int blocklen,
                                    const M2C_OpaqueType *stride,
                                    const M2C_OpaqueType *oldtype,
                                    M2C_OpaqueType *newtype, int *info,
                                    boolean_T *toplevel);

extern void mpi_Type_create_hvector_initialize(void);

extern void mpi_Type_create_hvector_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
