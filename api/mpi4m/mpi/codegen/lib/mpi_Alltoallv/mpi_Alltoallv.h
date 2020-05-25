#ifndef MPI_ALLTOALLV_H
#define MPI_ALLTOALLV_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Alltoallv_types.h"

extern void mpi_Alltoallv(const struct0_T *sptr, const emxArray_int32_T *scounts,
  const emxArray_int32_T *sdisps, const struct1_T *stype, const struct0_T *rptr,
  const emxArray_int32_T *rcounts, const emxArray_int32_T *rdisps, const
  struct1_T *rtype, const struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Alltoallv_initialize(void);
extern void mpi_Alltoallv_terminate(void);

#endif
