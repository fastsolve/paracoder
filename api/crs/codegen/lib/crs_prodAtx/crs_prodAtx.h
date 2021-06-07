#ifndef CRS_PRODATX_H
#define CRS_PRODATX_H

#include "crs_prodAtx_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_prodAtx(const CRS_Matrix *A, const emxArray_real_T *x,
                        emxArray_real_T *b, const emxArray_int32_T *nthreads);

extern void crs_prodAtx_initialize(void);

extern void crs_prodAtx_ser(const CRS_Matrix *A, const emxArray_real_T *x,
                            emxArray_real_T *b);

extern void crs_prodAtx_ser1(const CRS_Matrix *A, const emxArray_real_T *x,
                             emxArray_real_T *b);

extern void crs_prodAtx_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
