#ifndef MPI_PROBE_H
#define MPI_PROBE_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Probe_types.h"

extern void mpi_Probe(int source, int tag, const struct0_T *comm, struct0_T
                      *stat, int *info, boolean_T *toplevel);
extern void mpi_Probe_initialize(void);
extern void mpi_Probe_terminate(void);

#endif
