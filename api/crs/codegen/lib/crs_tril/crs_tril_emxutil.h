#ifndef CRS_TRIL_EMXUTIL_H
#define CRS_TRIL_EMXUTIL_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_tril_types.h"

extern void emxCopyStruct_CRS_Matrix(CRS_Matrix *dst, const CRS_Matrix *src);
extern void emxFreeStruct_CRS_Matrix(CRS_Matrix *pStruct);
extern void emxInitStruct_CRS_Matrix(CRS_Matrix *pStruct);

#endif
