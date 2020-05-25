#ifndef MPI_TOPO_TEST_H
#define MPI_TOPO_TEST_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mpi_Topo_test_types.h"

extern void mpi_Topo_test(const struct0_T *comm, int *topo_type, int *info,
  boolean_T *toplevel);
extern void mpi_Topo_test_initialize(void);
extern void mpi_Topo_test_terminate(void);

#endif
