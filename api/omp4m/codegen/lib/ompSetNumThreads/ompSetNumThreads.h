#ifndef OMPSETNUMTHREADS_H
#define OMPSETNUMTHREADS_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "ompSetNumThreads_types.h"

extern void ompSetNumThreads(int num_threads);
extern void ompSetNumThreads_initialize(void);
extern void ompSetNumThreads_terminate(void);

#endif
