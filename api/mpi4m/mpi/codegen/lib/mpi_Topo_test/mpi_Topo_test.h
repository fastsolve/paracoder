#ifndef MPI_TOPO_TEST_H
#define MPI_TOPO_TEST_H

#include "mpi_Topo_test_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void mpi_Topo_test(const M2C_OpaqueType *comm, int *topo_type, int *info,
                          boolean_T *toplevel);

extern void mpi_Topo_test_initialize(void);

extern void mpi_Topo_test_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
