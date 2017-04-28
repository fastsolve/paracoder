#ifndef CUMATCOPYSUBTOGPU_H
#define CUMATCOPYSUBTOGPU_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "cuMatCopySubToGPU_types.h"

extern void cuMatCopySubToGPU(int nrows, int ncols, const emxArray_real_T *mat,
  const struct0_T *cuMat, int *errCode, boolean_T *toplevel);
extern void cuMatCopySubToGPU_async(int nrows, int ncols, const emxArray_real_T *
  mat, const struct0_T *cuMat, const struct1_T *strm, int *errCode, boolean_T
  *toplevel);
extern void cuMatCopySubToGPU_initialize(void);
extern void cuMatCopySubToGPU_terminate(void);

#endif
