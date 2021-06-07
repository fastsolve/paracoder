#ifndef CRS_AXPY_H
#define CRS_AXPY_H

#include "crs_Axpy_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_Axpy(const CRS_Matrix *A, const emxArray_real_T *x,
                     emxArray_real_T *y, int nthreads);

extern void crs_Axpy_initialize(void);

extern void crs_Axpy_ser1(const CRS_Matrix *A, const emxArray_real_T *x,
                          emxArray_real_T *b);

extern void crs_Axpy_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
