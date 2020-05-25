#ifndef MPI_GET_STATUS_FIELD_H
#define MPI_GET_STATUS_FIELD_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_get_status_field_types.h"

extern int mpi_get_status_field(const struct0_T *stat, const emxArray_char_T
  *field);
extern void mpi_get_status_field_initialize(void);
extern void mpi_get_status_field_terminate(void);

#endif
