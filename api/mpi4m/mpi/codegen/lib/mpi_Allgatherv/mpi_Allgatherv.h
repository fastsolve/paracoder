#ifndef MPI_ALLGATHERV_H
#define MPI_ALLGATHERV_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Allgatherv_types.h"

extern void mpi_Allgatherv(const struct0_T *sptr, int scount, const struct1_T
  *stype, const struct0_T *rptr, const emxArray_int32_T *rcounts, const
  emxArray_int32_T *disps, const struct1_T *rtype, const struct1_T *comm, int
  *info, boolean_T *toplevel);
extern void mpi_Allgatherv_initialize(void);
extern void mpi_Allgatherv_terminate(void);

#endif
