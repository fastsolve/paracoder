#ifndef CUVECCOPYSUBTOGPU_H
#define CUVECCOPYSUBTOGPU_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuVecCopySubToGPU_types.h"

extern void cuVecCopySubToGPU(int n, const emxArray_real_T *vec, int istart, int
  inc, const struct0_T *cuVec, int incCuVec, int *errCode, boolean_T *toplevel);
extern void cuVecCopySubToGPU_async(int n, const emxArray_real_T *vec, int
  istart, int inc, const struct0_T *cuVec, int incCuVec, const struct1_T *strm,
  int *errCode, boolean_T *toplevel);
extern void cuVecCopySubToGPU_initialize(void);
extern void cuVecCopySubToGPU_terminate(void);

#endif
