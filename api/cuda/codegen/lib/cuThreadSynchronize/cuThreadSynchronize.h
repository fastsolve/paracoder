#ifndef CUTHREADSYNCHRONIZE_H
#define CUTHREADSYNCHRONIZE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuThreadSynchronize_types.h"

extern void cuThreadSynchronize(int *errCode, boolean_T *toplevel);
extern void cuThreadSynchronize_initialize(void);
extern void cuThreadSynchronize_terminate(void);

#endif
