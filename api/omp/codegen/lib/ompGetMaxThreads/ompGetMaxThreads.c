#include "ompGetMaxThreads.h"
#include "omp.h"

int ompGetMaxThreads(void)
{
  return omp_get_max_threads();
}

void ompGetMaxThreads_initialize(void)
{
}

void ompGetMaxThreads_terminate(void)
{
}
