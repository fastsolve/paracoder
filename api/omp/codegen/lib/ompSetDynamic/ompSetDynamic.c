#include "ompSetDynamic.h"
#include "omp.h"

void ompSetDynamic(int dynamic)
{
  omp_set_dynamic(dynamic);
}

void ompSetDynamic_initialize(void)
{
}

void ompSetDynamic_terminate(void)
{
}
