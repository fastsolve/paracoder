#ifndef CRS_SOLVE_TRIUT_H
#define CRS_SOLVE_TRIUT_H

#include "crs_solve_triut_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_solve_triut(const CRS_Matrix *A, emxArray_real_T *b);

extern void crs_solve_triut_initialize(void);

extern void crs_solve_triut_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
