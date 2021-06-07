#ifndef CRS_SOLVE_TRILT_H
#define CRS_SOLVE_TRILT_H

#include "crs_solve_trilt_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_solve_trilt(const CRS_Matrix *A, emxArray_real_T *b);

extern void crs_solve_trilt_initialize(void);

extern void crs_solve_trilt_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
