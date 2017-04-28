#ifndef CUBLASSETATOMICSMODE_H
#define CUBLASSETATOMICSMODE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuBlasSetAtomicsMode_types.h"

extern void cuBlasSetAtomicsMode(const struct0_T *hdl, int mode, int *errCode,
  boolean_T *toplevel);
extern void cuBlasSetAtomicsMode_initialize(void);
extern void cuBlasSetAtomicsMode_terminate(void);

#endif
