#ifndef CUBLASGETSTREAM_H
#define CUBLASGETSTREAM_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuBlasGetStream_types.h"

extern void cuBlasGetStream(const struct0_T *cubHdl, struct0_T *strm, int
  *errCode, boolean_T *toplevel);
extern void cuBlasGetStream_initialize(void);
extern void cuBlasGetStream_terminate(void);

#endif
