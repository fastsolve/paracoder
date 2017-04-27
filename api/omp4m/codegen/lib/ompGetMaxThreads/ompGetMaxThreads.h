#ifndef OMPGETMAXTHREADS_H
#define OMPGETMAXTHREADS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ompGetMaxThreads_types.h"

extern int ompGetMaxThreads(void);
extern void ompGetMaxThreads_initialize(void);
extern void ompGetMaxThreads_terminate(void);

#endif
