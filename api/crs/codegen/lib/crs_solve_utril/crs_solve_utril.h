#ifndef CRS_SOLVE_UTRIL_H
#define CRS_SOLVE_UTRIL_H

#include "crs_solve_utril_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_solve_utril(const CRS_Matrix *L, emxArray_real_T *b);

extern void crs_solve_utril_3args(const CRS_Matrix *L, emxArray_real_T *b,
                                  int offset);

extern void crs_solve_utril_initialize(void);

extern void crs_solve_utril_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
