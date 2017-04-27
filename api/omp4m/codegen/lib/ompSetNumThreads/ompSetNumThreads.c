#include "ompSetNumThreads.h"
#include "omp.h"

void ompSetNumThreads(int num_threads)
{
  omp_set_num_threads(num_threads);
}

void ompSetNumThreads_initialize(void)
{
}

void ompSetNumThreads_terminate(void)
{
}
