#ifndef MPI_INTERCOMM_CREATE_H
#define MPI_INTERCOMM_CREATE_H

#include "mpi_Intercomm_create_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Intercomm_create(const M2C_OpaqueType *local_comm,
                                 int local_leader,
                                 const M2C_OpaqueType *peer_comm,
                                 int remote_leader, int tag,
                                 M2C_OpaqueType *newcomm, int *info,
                                 boolean_T *toplevel);

extern void mpi_Intercomm_create_initialize(void);

extern void mpi_Intercomm_create_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
