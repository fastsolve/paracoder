#include "ompGetNumProcs.h"
#include "omp.h"

int ompGetNumProcs(void)
{
  return omp_get_num_procs();
}

void ompGetNumProcs_initialize(void)
{
}

void ompGetNumProcs_terminate(void)
{
}
