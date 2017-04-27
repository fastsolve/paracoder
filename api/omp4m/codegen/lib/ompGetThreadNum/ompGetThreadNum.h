#ifndef OMPGETTHREADNUM_H
#define OMPGETTHREADNUM_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ompGetThreadNum_types.h"

extern int ompGetThreadNum(void);
extern void ompGetThreadNum_initialize(void);
extern void ompGetThreadNum_terminate(void);

#endif
