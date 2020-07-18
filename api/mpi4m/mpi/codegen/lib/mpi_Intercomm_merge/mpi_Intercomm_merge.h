#ifndef MPI_INTERCOMM_MERGE_H
#define MPI_INTERCOMM_MERGE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Intercomm_merge_types.h"

extern void mpi_Intercomm_merge(const M2C_OpaqueType *intercomm, int high,
  M2C_OpaqueType *newcomm, int *info, boolean_T *toplevel);
extern void mpi_Intercomm_merge_initialize(void);
extern void mpi_Intercomm_merge_terminate(void);

#endif
