#ifndef OMPGETNUMPROCS_H
#define OMPGETNUMPROCS_H

#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern int ompGetNumProcs(void);

extern void ompGetNumProcs_initialize(void);

extern void ompGetNumProcs_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
