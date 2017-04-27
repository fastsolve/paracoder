#ifndef OMPSETNESTED_H
#define OMPSETNESTED_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "ompSetNested_types.h"

extern void ompSetNested(int nested);
extern void ompSetNested_initialize(void);
extern void ompSetNested_terminate(void);

#endif
