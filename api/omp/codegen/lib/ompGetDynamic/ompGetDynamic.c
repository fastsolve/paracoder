#include "ompGetDynamic.h"
#include "omp.h"

int ompGetDynamic(void)
{
  return omp_get_dynamic();
}

void ompGetDynamic_initialize(void)
{
}

void ompGetDynamic_terminate(void)
{
}
