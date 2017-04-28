#ifndef CUBLASGETPOINTERMODE_H
#define CUBLASGETPOINTERMODE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuBlasGetPointerMode_types.h"

extern void cuBlasGetPointerMode(const struct0_T *hdl, int *mode, int *errCode,
  boolean_T *toplevel);
extern void cuBlasGetPointerMode_initialize(void);
extern void cuBlasGetPointerMode_terminate(void);

#endif
