#ifndef CRS_DIAG_H
#define CRS_DIAG_H

#include "crs_diag_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_diag(const CRS_Matrix *A, emxArray_real_T *D);

extern void crs_diag1(const CRS_Matrix *A, int k, emxArray_real_T *D);

extern void crs_diag_initialize(void);

extern void crs_diag_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
