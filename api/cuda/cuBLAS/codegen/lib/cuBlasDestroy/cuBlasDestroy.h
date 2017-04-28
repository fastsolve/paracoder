#ifndef CUBLASDESTROY_H
#define CUBLASDESTROY_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuBlasDestroy_types.h"

extern void cuBlasDestroy(const struct0_T *hdl, int *errCode, boolean_T
  *toplevel);
extern void cuBlasDestroy_initialize(void);
extern void cuBlasDestroy_terminate(void);

#endif
