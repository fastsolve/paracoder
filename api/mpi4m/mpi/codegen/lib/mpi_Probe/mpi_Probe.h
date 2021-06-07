#ifndef MPI_PROBE_H
#define MPI_PROBE_H

#include "mpi_Probe_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Probe(int source, int tag, const M2C_OpaqueType *comm,
                      M2C_OpaqueType *stat, int *info, boolean_T *toplevel);

extern void mpi_Probe_initialize(void);

extern void mpi_Probe_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
