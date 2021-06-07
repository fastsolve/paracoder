#ifndef OMPGETWTICK_H
#define OMPGETWTICK_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern double ompGetWtick(void);

extern void ompGetWtick_initialize(void);

extern void ompGetWtick_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
