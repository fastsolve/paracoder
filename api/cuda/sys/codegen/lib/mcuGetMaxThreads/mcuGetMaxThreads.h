#ifndef MCUGETMAXTHREADS_H
#define MCUGETMAXTHREADS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "mcuGetMaxThreads_types.h"

extern void mcuGetMaxThreads(int *nthreads, int *threadsPB);
extern void mcuGetMaxThreads_initialize(void);
extern void mcuGetMaxThreads_terminate(void);

#endif
