#ifndef CUSTREAMHANDLEDESTROY_H
#define CUSTREAMHANDLEDESTROY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuStreamHandleDestroy_types.h"

extern void cuStreamHandleDestroy(const struct0_T *stm, int *errCode, boolean_T *
  toplevel);
extern void cuStreamHandleDestroy_initialize(void);
extern void cuStreamHandleDestroy_terminate(void);

#endif
