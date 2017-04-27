#include "ompGetThreadNum.h"
#include "omp.h"

int ompGetThreadNum(void)
{
  return omp_get_thread_num();
}

void ompGetThreadNum_initialize(void)
{
}

void ompGetThreadNum_terminate(void)
{
}
