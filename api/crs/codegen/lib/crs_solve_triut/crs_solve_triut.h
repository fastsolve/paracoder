#ifndef CRS_SOLVE_TRIUT_H
#define CRS_SOLVE_TRIUT_H
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "crs_solve_triut_types.h"

extern void crs_solve_triut(const CRS_Matrix *A, emxArray_real_T *b);
extern void crs_solve_triut_initialize(void);
extern void crs_solve_triut_terminate(void);

#endif
