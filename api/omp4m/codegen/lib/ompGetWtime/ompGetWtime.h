#ifndef OMPGETWTIME_H
#define OMPGETWTIME_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern double ompGetWtime(void);

extern void ompGetWtime_initialize(void);

extern void ompGetWtime_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
