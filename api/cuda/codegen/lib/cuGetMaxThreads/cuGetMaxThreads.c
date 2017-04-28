#include "cuGetMaxThreads.h"
#include "cuda4m.h"
#include "m2c.h"

void cuGetMaxThreads(int *nthreads, int *threadsPB)
{
  int dev;
  struct cudaDeviceProp t_prop;
  struct cudaDeviceProp * b_t_prop;
  int val;
  int b_val;
  cudaGetDevice(&dev);
  cudaGetDeviceProperties(&t_prop, dev);
  b_t_prop = (&t_prop);
  val = b_t_prop->multiProcessorCount;
  b_val = b_t_prop->maxThreadsPerMultiProcessor;
  *nthreads = val * b_val;
  *threadsPB = b_t_prop->warpSize;

}

void cuGetMaxThreads_initialize(void)
{
}

void cuGetMaxThreads_terminate(void)
{
}
