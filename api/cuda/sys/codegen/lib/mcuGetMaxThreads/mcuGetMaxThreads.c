#include "mcuGetMaxThreads.h"
#include "m2c.h"
#include "mcuda.h"

void mcuGetMaxThreads(int *nthreads, int *threadsPB)
{
  int dev;
  struct cudaDeviceProp t_prop;
  struct cudaDeviceProp * b_t_prop;
  int val;
  cudaGetDevice(&dev);
  cudaGetDeviceProperties(&t_prop, dev);
  b_t_prop = (&t_prop);
  dev = b_t_prop->multiProcessorCount;
  val = b_t_prop->maxThreadsPerMultiProcessor;
  *nthreads = dev * val;
  *threadsPB = b_t_prop->warpSize;

}

void mcuGetMaxThreads_initialize(void)
{
}

void mcuGetMaxThreads_terminate(void)
{
}
