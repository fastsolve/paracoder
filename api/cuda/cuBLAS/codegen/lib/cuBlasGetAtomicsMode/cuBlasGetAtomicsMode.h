#ifndef CUBLASGETATOMICSMODE_H
#define CUBLASGETATOMICSMODE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuBlasGetAtomicsMode_types.h"

extern void cuBlasGetAtomicsMode(const struct0_T *hdl, int *mode, int *errCode,
  boolean_T *toplevel);
extern void cuBlasGetAtomicsMode_initialize(void);
extern void cuBlasGetAtomicsMode_terminate(void);

#endif
