#ifndef CUSTREAMHANDLECREATE_H
#define CUSTREAMHANDLECREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuStreamHandleCreate_types.h"

extern void cuStreamHandleCreate(struct0_T *stm, int *errCode, boolean_T
  *toplevel);
extern void cuStreamHandleCreate_initialize(void);
extern void cuStreamHandleCreate_terminate(void);

#endif
