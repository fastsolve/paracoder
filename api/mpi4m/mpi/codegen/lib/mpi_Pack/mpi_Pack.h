#ifndef MPI_PACK_H
#define MPI_PACK_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Pack_types.h"

extern void mpi_Pack(const struct0_T *inbuf, int incount, const struct1_T
                     *datatype, const struct0_T *outbuf, int outcount, int
                     *position, const struct1_T *comm, int *info, boolean_T
                     *toplevel);
extern void mpi_Pack_initialize(void);
extern void mpi_Pack_terminate(void);

#endif
