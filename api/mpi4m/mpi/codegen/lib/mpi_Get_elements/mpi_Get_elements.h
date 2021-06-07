#ifndef MPI_GET_ELEMENTS_H
#define MPI_GET_ELEMENTS_H

#include "mpi_Get_elements_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Get_elements(const M2C_OpaqueType *stat,
                             const M2C_OpaqueType *datatype, int *elems,
                             int *info, boolean_T *toplevel);

extern void mpi_Get_elements_initialize(void);

extern void mpi_Get_elements_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
