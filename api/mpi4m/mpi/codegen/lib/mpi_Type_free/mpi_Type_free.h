#ifndef MPI_TYPE_FREE_H
#define MPI_TYPE_FREE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Type_free_types.h"

extern void mpi_Type_free(struct0_T *datatype, int *info, boolean_T *toplevel);
extern void mpi_Type_free_initialize(void);
extern void mpi_Type_free_terminate(void);

#endif
