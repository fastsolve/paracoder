#ifndef CUVECCOPYSUBFROMGPU_H
#define CUVECCOPYSUBFROMGPU_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuVecCopySubFromGPU_types.h"

extern void cuVecCopySubFromGPU(int n, const struct0_T *cuVec, int incCuVec,
  const emxArray_real_T *vec, int istart, int inc, int *errCode, boolean_T
  *toplevel);
extern void cuVecCopySubFromGPU_async(int n, const struct0_T *cuVec, int
  incCuVec, const emxArray_real_T *vec, int istart, int inc, const struct1_T
  *strm, int *errCode, boolean_T *toplevel);
extern void cuVecCopySubFromGPU_initialize(void);
extern void cuVecCopySubFromGPU_terminate(void);

#endif
