#ifndef OMPSETNESTED_H
#define OMPSETNESTED_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void ompSetNested(int nested);

extern void ompSetNested_initialize(void);

extern void ompSetNested_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
