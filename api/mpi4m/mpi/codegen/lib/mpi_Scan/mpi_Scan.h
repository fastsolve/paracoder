#ifndef MPI_SCAN_H
#define MPI_SCAN_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Scan_types.h"

extern void mpi_Scan(const struct0_T *sptr, const struct0_T *rptr, int count,
                     const struct1_T *datatype, const struct1_T *op, const
                     struct1_T *comm, int *info, boolean_T *toplevel);
extern void mpi_Scan_initialize(void);
extern void mpi_Scan_terminate(void);

#endif
