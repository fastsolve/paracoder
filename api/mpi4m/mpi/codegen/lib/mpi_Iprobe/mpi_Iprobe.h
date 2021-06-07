#ifndef MPI_IPROBE_H
#define MPI_IPROBE_H

#include "mpi_Iprobe_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Iprobe(int source, int tag, const M2C_OpaqueType *comm,
                       int *flag, M2C_OpaqueType *stat, int *info,
                       boolean_T *toplevel);

extern void mpi_Iprobe_initialize(void);

extern void mpi_Iprobe_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
