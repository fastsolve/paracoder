#ifndef CRS_PRODAATX_H
#define CRS_PRODAATX_H

#include "crs_prodAAtx_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_prodAAtx(const CRS_Matrix *A, const emxArray_real_T *x,
                         emxArray_real_T *b, emxArray_real_T *Atx,
                         const emxArray_int32_T *nthreads);

extern void crs_prodAAtx_initialize(void);

extern void crs_prodAAtx_ser(const CRS_Matrix *A, const emxArray_real_T *x,
                             emxArray_real_T *b);

extern void crs_prodAAtx_ser1(const CRS_Matrix *A, const emxArray_real_T *x,
                              emxArray_real_T *b);

extern void crs_prodAAtx_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
