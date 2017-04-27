#include "ompGetNested.h"
#include "omp.h"

int ompGetNested(void)
{
  return omp_get_nested();
}

void ompGetNested_initialize(void)
{
}

void ompGetNested_terminate(void)
{
}
