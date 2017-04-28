#ifndef CUGETMAXTHREADS_H
#define CUGETMAXTHREADS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "cuGetMaxThreads_types.h"

extern void cuGetMaxThreads(int *nthreads, int *threadsPB);
extern void cuGetMaxThreads_initialize(void);
extern void cuGetMaxThreads_terminate(void);

#endif
