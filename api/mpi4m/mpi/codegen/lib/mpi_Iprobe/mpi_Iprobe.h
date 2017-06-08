#ifndef MPI_IPROBE_H
#define MPI_IPROBE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Iprobe_types.h"

extern void mpi_Iprobe(int source, int tag, const struct0_T *comm, int *flag,
  struct0_T *stat, int *info, boolean_T *toplevel);
extern void mpi_Iprobe_initialize(void);
extern void mpi_Iprobe_terminate(void);

#endif
