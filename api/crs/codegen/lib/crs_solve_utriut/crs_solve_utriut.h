#ifndef CRS_SOLVE_UTRIUT_H
#define CRS_SOLVE_UTRIUT_H

#include "crs_solve_utriut_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_solve_utriut(const CRS_Matrix *U, emxArray_real_T *b);

extern void crs_solve_utriut_3args(const CRS_Matrix *U, emxArray_real_T *b,
                                   int offset);

extern void crs_solve_utriut_initialize(void);

extern void crs_solve_utriut_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
