#ifndef OMPGETMAXTHREADS_H
#define OMPGETMAXTHREADS_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int ompGetMaxThreads(void);

extern void ompGetMaxThreads_initialize(void);

extern void ompGetMaxThreads_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
