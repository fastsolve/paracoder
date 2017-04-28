#ifndef CUBLASSETSTREAM_H
#define CUBLASSETSTREAM_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuBlasSetStream_types.h"

extern void cuBlasSetStream(const struct0_T *hdl, const struct0_T *strm, int
  *errCode, boolean_T *toplevel);
extern void cuBlasSetStream_initialize(void);
extern void cuBlasSetStream_terminate(void);

#endif
