#ifndef MPI_ALLTOALLW_H
#define MPI_ALLTOALLW_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Alltoallw_types.h"

extern void mpi_Alltoallw(const struct0_T *sptr, const emxArray_int32_T *scounts,
  const emxArray_int32_T *sdisps, const struct1_T *stypes, const struct0_T *rptr,
  const emxArray_int32_T *rcounts, const emxArray_int32_T *rdisps, const
  struct1_T *rtypes, const struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Alltoallw_initialize(void);
extern void mpi_Alltoallw_terminate(void);

#endif
