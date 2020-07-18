#ifndef MPI_GROUP_FREE_H
#define MPI_GROUP_FREE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Group_free_types.h"

extern void mpi_Group_free(M2C_OpaqueType *group, int *info, boolean_T *toplevel);
extern void mpi_Group_free_initialize(void);
extern void mpi_Group_free_terminate(void);

#endif
