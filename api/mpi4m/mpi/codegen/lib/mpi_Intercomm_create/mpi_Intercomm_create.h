#ifndef MPI_INTERCOMM_CREATE_H
#define MPI_INTERCOMM_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "mpi_Intercomm_create_types.h"

extern void mpi_Intercomm_create(const struct0_T *local_comm, int local_leader,
  const struct0_T *peer_comm, int remote_leader, int tag, struct0_T *newcomm,
  int *info, boolean_T *toplevel);
extern void mpi_Intercomm_create_initialize(void);
extern void mpi_Intercomm_create_terminate(void);

#endif
