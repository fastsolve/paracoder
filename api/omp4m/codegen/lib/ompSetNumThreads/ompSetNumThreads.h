#ifndef OMPSETNUMTHREADS_H
#define OMPSETNUMTHREADS_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ompSetNumThreads(int num_threads);

extern void ompSetNumThreads_initialize(void);

extern void ompSetNumThreads_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
