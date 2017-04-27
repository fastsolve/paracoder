#include "ompGetWtick.h"
#include "omp.h"

double ompGetWtick(void)
{
  return omp_get_wtick();
}

void ompGetWtick_initialize(void)
{
}

void ompGetWtick_terminate(void)
{
}
