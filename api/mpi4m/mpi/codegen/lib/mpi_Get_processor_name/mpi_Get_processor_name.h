#ifndef MPI_GET_PROCESSOR_NAME_H
#define MPI_GET_PROCESSOR_NAME_H

#include "mpi_Get_processor_name_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Get_processor_name(emxArray_char_T *name, int *info,
                                   boolean_T *toplevel);

extern void mpi_Get_processor_name_initialize(void);

extern void mpi_Get_processor_name_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
