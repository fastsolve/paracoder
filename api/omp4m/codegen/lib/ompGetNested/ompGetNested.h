#ifndef OMPGETNESTED_H
#define OMPGETNESTED_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int ompGetNested(void);

extern void ompGetNested_initialize(void);

extern void ompGetNested_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
