#ifndef OMPSETDYNAMIC_H
#define OMPSETDYNAMIC_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ompSetDynamic(int dynamic);

extern void ompSetDynamic_initialize(void);

extern void ompSetDynamic_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
