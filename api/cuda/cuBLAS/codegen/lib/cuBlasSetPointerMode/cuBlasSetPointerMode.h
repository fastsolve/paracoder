#ifndef CUBLASSETPOINTERMODE_H
#define CUBLASSETPOINTERMODE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuBlasSetPointerMode_types.h"

extern void cuBlasSetPointerMode(const struct0_T *hdl, int mode, int *errCode,
  boolean_T *toplevel);
extern void cuBlasSetPointerMode_initialize(void);
extern void cuBlasSetPointerMode_terminate(void);

#endif
