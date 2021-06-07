#ifndef OMPGETNUMTHREADS_H
#define OMPGETNUMTHREADS_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int ompGetNumThreads(void);

extern void ompGetNumThreads_initialize(void);

extern void ompGetNumThreads_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
