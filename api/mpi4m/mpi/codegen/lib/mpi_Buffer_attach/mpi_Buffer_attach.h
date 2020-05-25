#ifndef MPI_BUFFER_ATTACH_H
#define MPI_BUFFER_ATTACH_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Buffer_attach_types.h"

extern void mpi_Buffer_attach(const struct0_T *ptr, int size, int *info,
  boolean_T *toplevel);
extern void mpi_Buffer_attach_initialize(void);
extern void mpi_Buffer_attach_terminate(void);

#endif
