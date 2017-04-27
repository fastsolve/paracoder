#ifndef OMPGETNUMTHREADS_H
#define OMPGETNUMTHREADS_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ompGetNumThreads_types.h"

extern int ompGetNumThreads(void);
extern void ompGetNumThreads_initialize(void);
extern void ompGetNumThreads_terminate(void);

#endif
