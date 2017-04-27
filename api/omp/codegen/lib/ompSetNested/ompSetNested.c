#include "ompSetNested.h"
#include "omp.h"

void ompSetNested(int nested)
{
  omp_set_nested(nested);
}

void ompSetNested_initialize(void)
{
}

void ompSetNested_terminate(void)
{
}
