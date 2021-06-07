#ifndef CRS_SOLVE_TRIU_H
#define CRS_SOLVE_TRIU_H

#include "crs_solve_triu_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void crs_solve_triu(const CRS_Matrix *A, emxArray_real_T *b);

extern void crs_solve_triu_initialize(void);

extern void crs_solve_triu_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
