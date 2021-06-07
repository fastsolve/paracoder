#ifndef OMPGETDYNAMIC_H
#define OMPGETDYNAMIC_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int ompGetDynamic(void);

extern void ompGetDynamic_initialize(void);

extern void ompGetDynamic_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
