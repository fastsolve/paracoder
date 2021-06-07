#ifndef OMPGETTHREADNUM_H
#define OMPGETTHREADNUM_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int ompGetThreadNum(void);

extern void ompGetThreadNum_initialize(void);

extern void ompGetThreadNum_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
