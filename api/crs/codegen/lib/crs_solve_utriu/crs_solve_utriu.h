#ifndef CRS_SOLVE_UTRIU_H
#define CRS_SOLVE_UTRIU_H

#include "crs_solve_utriu_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_solve_utriu(const CRS_Matrix *U, emxArray_real_T *b);

extern void crs_solve_utriu_3args(const CRS_Matrix *L, emxArray_real_T *b,
                                  int offset);

extern void crs_solve_utriu_initialize(void);

extern void crs_solve_utriu_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
