#include "mpi_Abort.h"
#include "m2c.h"

static void m2c_error(void);
static void m2c_error(void)
{
  M2C_error("MMPI:MPI_Abort", "MPI_Abort was called");
}

int mpi_Abort(const M2C_OpaqueType *comm, int errorcode)
{
  int info;
  (void)comm;
  (void)errorcode;
  info = 0;
  m2c_error();
  return info;
}

void mpi_Abort_initialize(void)
{
}

void mpi_Abort_terminate(void)
{
}
