#ifndef MPI_GET_STATUS_FIELD_H
#define MPI_GET_STATUS_FIELD_H

#include "mpi_get_status_field_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int mpi_get_status_field(const M2C_OpaqueType *stat,
                                const emxArray_char_T *field);

extern void mpi_get_status_field_initialize(void);

extern void mpi_get_status_field_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
