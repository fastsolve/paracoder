#ifndef CRS_TRIL_EMXUTIL_H
#define CRS_TRIL_EMXUTIL_H

#include "crs_tril_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void emxCopyStruct_CRS_Matrix(CRS_Matrix *dst, const CRS_Matrix *src);

extern void emxCopy_int32_T(emxArray_int32_T **dst,
                            emxArray_int32_T *const *src);

extern void emxCopy_real_T(emxArray_real_T **dst, emxArray_real_T *const *src);



extern void emxFreeStruct_CRS_Matrix(CRS_Matrix *pStruct);



extern void emxInitStruct_CRS_Matrix(CRS_Matrix *pStruct);



#ifdef __cplusplus
}
#endif

#endif
