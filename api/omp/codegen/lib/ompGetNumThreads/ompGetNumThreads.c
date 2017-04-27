#include "ompGetNumThreads.h"
#include "omp.h"

int ompGetNumThreads(void)
{
  return omp_get_num_threads();
}

void ompGetNumThreads_initialize(void)
{
}

void ompGetNumThreads_terminate(void)
{
}
