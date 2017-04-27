#include "mpi_Wtime.h"
#include "mpi.h"

double mpi_Wtime(void)
{
  return MPI_Wtime();
}

void mpi_Wtime_initialize(void)
{
}

void mpi_Wtime_terminate(void)
{
}
