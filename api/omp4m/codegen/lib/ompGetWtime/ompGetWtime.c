#include "ompGetWtime.h"
#include "omp.h"

double ompGetWtime(void)
{
  return omp_get_wtime();
}

void ompGetWtime_initialize(void)
{
}

void ompGetWtime_terminate(void)
{
}
