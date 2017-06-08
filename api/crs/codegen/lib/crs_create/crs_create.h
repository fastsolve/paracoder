#ifndef CRS_CREATE_H
#define CRS_CREATE_H
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rtwtypes.h"
#include "crs_create_types.h"

extern void crs_create(const emxArray_int32_T *rows, const emxArray_int32_T
  *cols, const emxArray_real_T *vs, struct0_T *A);
extern void crs_create0(int ni, int nj, struct1_T *A);
extern void crs_create1(const emxArray_int32_T *is, const emxArray_int32_T *js,
  const emxArray_real_T *vs, int ni, int nj, struct0_T *A);
extern void crs_create_initialize(void);
extern void crs_create_terminate(void);

#endif
